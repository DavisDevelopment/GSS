class GSSNode {
	public var type:String;
	public var name:String;
	public var value:String;
	public var indents:Int = 4;
	private var hasParent:Bool;
	private var parent:GSSNode;
	private var childNodes:Array<GSSNode>;
	private var toAppendAfter:Array <String>;
	
	public function new( type:String ) {
		this.type = type;
		this.childNodes = [];
		this.toAppendAfter = [];
		this.hasParent = false;
	}
	
	private function getIndentation():String {
		var indentations:Int = 0;
		
		if ( this.hasParent ) indentations += this.indents;
		
		var spaces:String = "";
		for ( i in 0...indentations ) spaces += " ";
		return spaces;
	}
	
	public function appendChild( child:GSSNode ):Void {
		this.childNodes.push( child );
		child.setParent( this );
	}
	
	public function setParent( parent:GSSNode ):Void {
		this.parent = parent;
		if ( !this.hasParent ) this.hasParent = true;
	}
	
	public function setName( name:String ):Void {
		this.name = name;
	}
	public function setValue( val:String ):Void {
		this.value = val;
	}
	
	private function getPrefixes( name:String ):Array <String> {
		var prefixer:Map <String, Array<String>> = [
			"align-content" => ["webkit"],
			"align-items" => ["webkit"],
			"align-self" => ["webkit"],
			"animation" => ["webkit"],
			"background-size" => ["webkit"],
			"border-image" => ["webkit", "o"],
			"border-radius" => ["webkit"],
			"linear-gradient" => ["webkit"]
		];
		if (prefixer.get(name) != null) {
			return prefixer.get(name);
		} else {
			return ["webkit", "moz", "o", "ms"];
		}
	}
	
	public function getValue(?variables:Mapper<String, String>, ?mixins:Mapper<String, GSSNode>):String {
		function getFullSelectorString( obj:GSSNode ):String {
			var selectorList:Array <String> = [];
			if ( obj.type == "selector" || obj.type == "when_pseudo" ) {
				selectorList.push( obj.value );
				if ( obj.hasParent ) {
					selectorList.push(getFullSelectorString(obj.parent));
				}
			}
			selectorList.reverse();
			var selector:String = selectorList.join(" ");
			return selector;
		}
		if ( this.type == "selector" ) {
			var selector:String = getFullSelectorString( this );
			var val:String = '${selector} {\n';
			for ( child in this.childNodes ) {
				if ( child.type == "prop_assignment" || child.type == "mixin_reference" ) {
					if ( child.type == "mixin_reference" ) for ( x in child.childNodes ) x.setParent(this);
					val += child.getValue( variables, mixins );
					val += "\n";
				}
				else if ( child.type == "selector" || child.type == "when_pseudo" ) {
					this.toAppendAfter.push( child.getValue(variables, mixins) );
				}
			}
			val += "}\n";
			for ( item in this.toAppendAfter ) val += item;
			return val;
		}
		else if ( this.type == "prop_assignment" ) {
			/*
			When property name is preceded by the tilde (~) key, the compiler automatically replicates that property assignment,
			prefixing it with all major vendor prefixes.
			*/
			var vendorPrefixes:Array <String> = getPrefixes(this.name.substring(1)), mode:String = "normal";
			//Determine generation mode
			if ( this.name.substring(0,1) == "~" ) {
				mode = "prefixed";
			}
			var val:String = "", value:String = "";
			if ( this.value.substring(0,1) == "@" ) { //Variable Reference
				var name:String = this.value.substring(1,this.value.length);
				if ( variables.get( name ) != null ) value += variables.get(name);
			}
			else {
				value += this.value;
			}
			//Based on mode, either generate 5 prop definitions (4 with prefixes, 1 without), or only generate one.
			var spaces:String = this.getIndentation();
			if ( mode == "prefixed" ) {
				var name:String = this.name.substring(1, this.name.length);
				val += spaces+'$name : $value;\n';
				for ( prefix in vendorPrefixes ) {
					val += spaces+'-${prefix}-$name : $value;\n';
				}
			} else {
				val += spaces+'${this.name} : $value;';
			}
			return val;
		}
		else if ( this.type == "when_pseudo" ) {
			if ( this.hasParent ) {
				var rawSelector:String = getFullSelectorString( this ) + ":" + this.name;
				var selector:String = StringTools.replace(rawSelector, " null", "");
				selector = StringTools.replace(selector, " :", ":");
				var val:String = '$selector {\n';
				for ( child in this.childNodes ) {
					if ( child.type == "selector" ) {
						var stuff:String = StringTools.replace(child.getValue(variables, mixins), rawSelector, selector);
						stuff = StringTools.replace(stuff, " null", "");
						stuff = StringTools.replace(stuff, this.parent.value, (this.parent.value+":"+this.name));
						this.toAppendAfter.push( stuff );
					} else {
						val += child.getValue(variables, mixins);
						val += "\n";
					}
				}
				val += "}\n";
				for (item in this.toAppendAfter) {
					val += item;
				}
				return val;
			} else {
				return "";
			}
		}
		else if ( this.type == "var_assignment" ) {
			variables.set(this.name, this.value);
			return "";
		}
		else if ( this.type == "mixin_declaration" ) {
			mixins.set(this.name, this);
			return "";
		}
		else if ( this.type == "mixin_reference" ) {
			if ( mixins.get(this.name) != null ) {
				var mixin:GSSNode = mixins.get(this.name);
				var val:String = "";
				for ( child in mixin.childNodes ) {
					if ( child.type == "selector" || child.type == "when_pseudo" ) {
						var selector:String = getFullSelectorString( this.parent );
						trace("THIS IS THE SELECTOR:");
						trace( selector );
						var thatVal:String = (child.getValue(variables, mixins));
						trace( thatVal );
						this.parent.toAppendAfter.push(selector+thatVal);
					} else {
						val += child.getValue(variables, mixins);
						val += "\n";
					}
				}
				return val;
			} else {
				throw 'ReferenceError:  ${ this.name } is either not defined, or not a valid mixin.';
			}
		}
		//Comments
		else if ( this.type == "comment" ) {
			return '/*\n${this.value}\n*/';
		}
		//Strings
		else if ( this.type == "string" ) {
			return '\"${this.value}\"';
		}
		else {
			return "";
		}
	}
	public function getChildren():Array <GSSNode> {
		return this.childNodes;
	}
}