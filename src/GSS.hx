
class Console {
	public static function log( x:Dynamic ):Void {
		var debug:Bool = false;
		if ( debug ) trace( x );
	}
}

@:expose class GSS {
	private var doExport:Bool;
	private var variables:Mapper<String, String>;
	private var mixins:Mapper<String, GSSNode>;
	private var functions:Mapper<String, GSSFunction>;
	private var helpers:Mapper<String, GSSHelper>;
	public var getFile:String->String;
	public var __dir__:String;
	public function new( ?getFile:String->String, ?dir:String, ?doExport:Bool=false ) {
		if ( getFile == null ) getFile = function( path:String ):String {
			return "";
		};
		this.doExport = doExport;
		this.variables = new Mapper();
		this.mixins = new Mapper();
		this.functions = new Mapper();
		this.helpers = new Mapper();
		this.getFile = getFile;
		this.__dir__ = dir;
	}
	
	public function register( name:String, func:Array<String> -> Array<GSSNode> ):Void {
		var ourFunc:GSSFunction = new GSSFunction( func );
		this.functions.set( name, ourFunc );
	}
	public function helper( name:String, func:Array<String> -> String ):Void {
		var ourFunc:GSSHelper = new GSSHelper( func );
		this.helpers.set( name, ourFunc );
	}
	public function set( type:String, name:String, what:Dynamic ) {
		var prop = Reflect.getProperty(this, (type+'s'));
		var strProcess = function( x:String ):String { return x; };
		var funcProcess = function( x:Array <String> -> Array <GSSNode> ):GSSFunction {
			return new GSSFunction( x );
		};
		var helperProcess = function( x:Array <String> -> String ):GSSHelper {
			return new GSSHelper(x);
		};
		var defProcess = function( x:Dynamic ):Dynamic { return x; };
		if ( prop != null ) {
			switch( type ) {
				case "variable":
					this.variables.set(name, strProcess(what));
				case "function":
					this.functions.set(name, funcProcess(what));
				case "helper":
					this.helpers.set(name, helperProcess(what));
				default:
					Console.log("Anal Testicles");
			}
		}
		else throw 'GSS object has no field ${type}s.';
	}
	
	private function isSymbol( c:String ):Bool {
		return ~/[\{\}\(\):;,]/.match( c );
	}
	private function isKeyword( c:String ):Bool {
		return ~/mixin|extends|import|when|hovered|active/.match( c );
	}
	private function isWhiteSpace( c:String ):Bool {
		return ~/\s/.match( c );
	}
	private function isLineBreaker( c:String ):Bool {
		return (~/[\n\r]/).match( c );
	}
	private function isDigit( c:String ):Bool {
		return ~/[0-9]/.match( c );
	}
	private function isIdentifier( c:String ):Bool {
		return ( !isWhiteSpace(c) && !isSymbol(c) );
	}
	private function isPseudoClassName( c:String ):Bool {
		var pseudoClasses:Array <String> = [
			"active", "first-letter", "first-line",
			"focused", "hover", "link", "visited"
		];
		var ret:Bool = false;
		for ( v in pseudoClasses ) {
			if ( v == c ) {
				ret = true;
				break;
			}
		}
		return ret;
	}
	
	public function lex( stringInput:String ):Array<Array<String>> {
		var input:Array<String> = stringInput.split("");
		var tokenList:Array<Array<String>> = [];
		var i:Int = 0, c:String;
		
		function addToken(type:String, value:String):Void {
			tokenList.push([type, value]);
		}
		function advance( dis:Int=1 ):Void {
			i += dis;
			c = input[i];
		}
		function next( dis:Int=1 ):String {
			return input[i+dis];
		}
		
		while ( i < input.length ) {
			c = input[i];
			
			if ( isWhiteSpace(c) ) {
				var dis:Int = 1;
				while ( isWhiteSpace(next(dis)) ) dis++;
				advance( dis );
			}
			else if ( isSymbol(c) ) {
				addToken("symbol", c);
				advance();
			}
			//Strings
			else if ( ~/["']/.match(c) ) {
				var delimiter:String = c, dis:Int = 1, val:String = "";
				while( next(dis) != delimiter ) {
					val += next(dis);
					
					dis++;
				}
				advance( dis+1 );
				addToken("string", val);
			}
			//Block Comment
			else if ( c == "/" && next() == "/" ) {
				var comment:String = "", dis:Int = 2;
				while ( !isLineBreaker(next(dis)) ) {
					comment += next(dis);
					dis++;
					Console.log( next(dis) );
				}
				advance(dis);
				addToken("block_comment", comment);
			}
			//Stream Comment
			else if ( c == "/" && next() == "*" ) {
				var comment:String = "", dis:Int = 2;
				while (!(next(dis) == "*" && next(dis+1) == "/")) {
					comment += next(dis);
					
					dis++;
				}
				advance( dis+2 );
				addToken("stream_comment", comment);
			}
			//Identifiers and PseudoClasses
			else if ( isIdentifier(c) ) {
				var val:String = c;
				var dis:Int = 1;
				while( isIdentifier(next(dis)) ) {
					val += next(dis);
					dis++;
				}
				if ( isKeyword(val) ) {
					addToken("keyword", val);
				}
				else if ( isPseudoClassName(val) ) {
					addToken("pseudo_class", val);
				} else {
					addToken("identifier", val);
				}
				advance(dis);
			}			
			else {
				throw 'LexError: Unexpected $c.';
			}
		}
		
		return tokenList;
	}
	
	public function parse( tokens:Array<Array<String>> ):Array<GSSNode> {
		var nodeTree:Array<GSSNode> = [];
		var mixinList:Mapper<String, GSSNode> = this.mixins;
		var i:Int = 0, token:Array<String>;
		function addNode( node:GSSNode ) {
			nodeTree.push( node );
		}
		function advance( dis:Int=1 ):Void {
			i += dis;
			token = tokens[i];
		}
		function next( dis:Int=1 ):Array<String> {
			return tokens[i+dis];
		}
		
		function parseStyleGroup( group:Array<Array<String>> ):Array <GSSNode> {
			var styleGroup:Array <GSSNode> = [];
			var i:Int = 0, token:Array <String> = group[i];
			Console.log( group );
			
			while ( i < group.length ) {
				token = group[i];
				//Console.log( token );
				
				//Mixin Reference
				if ( group[i][0] == "identifier" && group[i+1][1] == ";" ) {
					var node:GSSNode = new GSSNode( "mixin_reference" );
					node.setName( token[1] );
					styleGroup.push( node );
					
					i += 2;
				}
				//Style Groups ( Inline Styles )
				else if ( (token[0] == "identifier" && group[i+1][1] == "{") || (token[0] == "identifier" && group[i+1][0] == "identifier") || (token[0] == "identifier" && group[i+1][1] == ":" && group[i+2][0] == "pseudo_class") ) {
					var dis:Int = 1, selector:String = token[1];
					while ( group[i+dis][0] == "identifier" || group[i+dis][1] == ":" || group[i+dis][0] == "pseudo_class" ) {
						if (!(group[i+dis][1] == ":" || group[i+dis-1][1] == ":")) selector += " ";
						selector += group[i+dis][1];
						dis++;
					}
					i += dis;
					var node:GSSNode = new GSSNode( "selector" );
					node.setValue( selector );
					if ( group[i][1] == "{" ) {
						var d:Int = 1, list:Array <Array<String>> = [];
						var brackets:Int = 1;
						while ( brackets > 0 ) {
							if ( group[i+d][1] == "{" ) brackets++;
							else if ( group[i+d][1] == "}" ) brackets--;
							
							if(!(group[i+d][1] == "}" && brackets == 0)) {
								list.push( group[i+d] );
							}
							d++;
						}
						var children:Array <GSSNode> = parseStyleGroup( list );
						for ( child in children ) node.appendChild( child );
						i += d;
						styleGroup.push( node );
					} else {
						Console.log( group[i] );
						throw "SyntaxError:  Unexpected Selector String.";
					}
					
				}
				//'when' pseudoclass alternative
				else if ( token[0] == "keyword" && token[1] == "when" && group[i+1][0] == "keyword" ) {
					var node:GSSNode = new GSSNode( "when_pseudo" );
					var pseudoNames:Map<String, String> = [
						"active" => "active",
						"hovered" => "hover"
					];
					node.setName(pseudoNames.get(group[i+1][1]));
					i += 2;
					//Collect Tokens
					var d:Int = 1, list:Array<Array<String>> = [], brackets:Int = 1;
					
					while ( brackets > 0 ) {
						if ( group[i+d][1] == "{" ) brackets++;
						else if ( group[i+d][1] == "}" ) brackets--;
						if (!(group[i+d][1] == "}" && brackets == 0)) {
							list.push(group[i+d]);
						}
						d++;
					}
					i += d;
					//Parse tokens into GSSNodes
					var children:Array<GSSNode> = parseStyleGroup(list);
					for ( child in children ) node.appendChild(child);
					styleGroup.push(node);
				}
				//Property Definition
				else if ( token[0] == "identifier" && group[i+1][1] == ":" && group[i+2][0] == "identifier" ) {
					var mode:String = "prop_assignment";
					var valType:String = "normal";
					if ( group[i+3][1] == "(" ) valType = "helper_call";
					var val:String = "", d:Int = 0;
					
					//Standard Property Definition
					if ( valType == "normal" ) {
						d = 3;
						val = group[i+2][1];
						while ( group[i+d][1] != ";" ) {
							val += (" " + group[i+d][1]);
							d++;
						}
					//Helper Function Invocation
					} else {
						var dis:Int = 4, args:Array <String> = [], ref:String = group[i+2][1];
						while ( group[i+dis][1] != ")" ) {
							if ( group[i+dis][1] != "," ) {
								args.push(StringTools.ltrim(StringTools.rtrim(group[i+dis][1])));
							}
							dis++;
						}
						i += dis + 1;
						//If it's a valid helper function
						if ( this.helpers.get(ref) != null ) {
							var func:GSSHelper = this.helpers.get(ref);
							//Then set the node's value to the return value of that helper function
							val = func.__call__( args );
						//Otherwise
						} else {
							//Set the node's value to a string representation of the function call
							val = '$ref(${args.join(",")})';
						}
					}
					var node:GSSNode;
					//if ( mode == "prop_assignment" ) {
						node = new GSSNode( "prop_assignment" );
						node.setName( token[1] );
						node.setValue( val );
					//}
					// else {
						// var selector:String = (group[i][1] + ":" + group[i+1][1]);
						// node = new GSSNode( "selector" );
						// node.setValue( selector );
						// var d:Int = 1, brackets:Int = 1, list:Array <Array<String>> = [];
						// while ( brackets > 0 ) {
							// if ( group[i+d][1] == "{" ) brackets++;
							// else if ( group[i+d][1] == "}" ) brackets--;
							// if (!(group[i+d][1] == "{" &&  brackets == 0)) {
								// list.push( group[i+d] );
							// }
							// d++;
						// }
						// var children:Array <GSSNode> = parseStyleGroup( list );
						// for ( child in children ) node.appendChild( child );
					// }
					styleGroup.push( node );
					
					i += d+1;
				}
				//Function Invocation
				else if ( group[i][0] == "identifier" && group[i+1][1] == "(" ) {
					var dis:Int = 2, args:Array <String> = [];
					var ref:String = group[i][1];
					while ( group[i+dis][1] != ")" ) {
						if ( group[i+dis][1] != "," ) {
							args.push( StringTools.ltrim(StringTools.rtrim(group[i+dis][1])) );
						}
						dis++;
					}
					i += dis+2;
					if ( this.functions.get(ref) != null ) {
						var mixedIn:Array <GSSNode> = this.functions.get(ref).__call__( args );
						for ( x in mixedIn ) styleGroup.push(x);
					} else {
						Console.log( this.functions.keys );
						throw 'ReferenceError: $ref is either not defined, or not a valid function.';
					}
				}
				else {
					Console.log( nodeTree );
					throw 'Unexpected Token $token.';
				}
			}
			
			return styleGroup;
		}
		
		function parseToken( tk:Array<String>, ?parent:GSSNode ):GSSNode {
			var type:String = tk[0], value:String = tk[1];
			
			//Selector Strings
			if ( (type == "identifier" && next()[1] == "{") || (type == "identifier" && next()[0] == "identifier")) {
				var dis:Int = 1, selector:String = value;
				while ( next(dis)[0] == "identifier" || next(dis)[1] == ":" ) {
					if (!(next(dis)[1] == ":" || next(dis-1)[1] == ":")) selector += " ";
					selector += next(dis)[1];
					dis++;
				}
				var node:GSSNode = new GSSNode( "selector" );
				node.setValue( selector );
				advance(dis);
				if ( token[1] == "{" ) {
					var brackets:Int = 1, dis = 1, list:Array<Array<String>> = [];
					while ( brackets > 0 ) {
						if ( next(dis)[1] == "{" ) brackets++;
						else if ( next(dis)[1] == "}" ) brackets--;
						
						if (!(next(dis)[1] == "}" && brackets == 0)) {
							list.push( next(dis) );
						}
						
						dis++;
					}
					advance( dis );
					var children:Array <GSSNode> = parseStyleGroup( list );
					for ( child in children ) node.appendChild(child);
				}
				return node;
			}
			//Style Group Body
			else if ( type == "symbol" && value == "{" && parent != null ) {
				var dis:Int = 0, children:Array<GSSNode> = [];
				var openingBrackets:Int = 1, closingBrackets:Int = 0;
				while ( openingBrackets != closingBrackets ) {
					if ( next(dis)[1] == "{" ) openingBrackets++;
					else if ( next(dis)[1] == "}" ) closingBrackets++;
					var n:Array<String> = next(dis);
					//Normal Property Assignment
					if ( n[0] == "identifier" && next(dis+1)[1] == ":" && next(dis+2)[0] == "identifier" ) {
						var node:GSSNode = new GSSNode( "prop_assignment" );
						node.setName( n[1] );
						var val:String = next(dis+2)[1], d:Int = 3;
						while ( next(dis+d)[1] != ";" ) {
							val += (" " + next(dis+d)[1]);
							d++;
						}
						node.setValue( val );
						parent.appendChild( node );
						dis += d+1;
					}
					//Mixin Reference
					else if ( next(dis)[0] == "identifier" && next(dis+1)[1] == ";" ) {
						var node:GSSNode = new GSSNode( "mixin_reference" );
						node.setName( n[1] );
						parent.appendChild(node);
						dis += 2;
					}
					else {
						dis++;
					}
				}
				advance( dis + 1 );
				return parent;
			}
			//Variable Assignment
			else if ( type == "identifier" && next()[1] == ":" && next(2)[0] == "identifier" && next(3)[1] == ";" ) {
				if ( value.split("")[0] == "@" ) {
					var name:String = value.substring(1, value.length);
					var val:String = next(2)[1];
					var node:GSSNode = new GSSNode( "var_assignment" );
					node.setName( name );
					node.setValue( val );
					advance( 4 );
					return node;
				} else {
					throw 'Unexpected Property Assignment: [$value : ${next(2)[1]}]';
				}
			}
			//Mixin Declaration
			else if ( type == "keyword" && value == "mixin" && next()[0] == "identifier" ) {
				var mixinType:String;
				if ( next(2)[1] == "(" ) mixinType = "parametric";
				else {
					mixinType = "normal";
				}
				
				//Standard Mixin
				if ( mixinType == "normal" ) {
					var node:GSSNode = new GSSNode( "mixin_declaration" );
					var mode:String = "";
					var name:String = next()[1];
					node.setName( name );
					var inherits:Bool = false, from:Array <String> = [];
					if ( next(2)[0] == "keyword" && next(2)[1] == "extends" ) {
						inherits = true;
						if ( next(3)[0] == "identifier" ) {
							mode = "single";
							from.push( next(3)[1] );
						}
						else if ( next(3)[1] == "(" ) {
							mode = "multiple";
						}
					}
					if ( mode == "multiple" ) {
						var dis:Int = 4;
						while( next(dis)[1] != ")" ) {
							var ref:String = StringTools.ltrim(StringTools.rtrim(next(dis)[1]));
							if ( next(dis)[1] != "," ) {
								Console.log( ref );
								from.push(ref);
							}
							dis++;
						}
						advance( dis );
					}
					
					var brackets:Int = 1, list:Array <Array<String>> = [], dis:Int = (inherits?((mode=="multiple")?2:5):3);
					while( brackets > 0 ) {
						Console.log( next(dis) );
						if ( next(dis)[1] == "{" ) brackets++;
						else if ( next(dis)[1] == "}" ) brackets--;
						if (!(next(dis)[1] == "}" && brackets == 0)) {
							list.push( next(dis) );
						}
						dis++;
					}
					advance(dis);
					var children:Array <GSSNode> = parseStyleGroup( list );
					if ( inherits ) {
						for ( parent in from ) {
							if ( mixinList.get(parent) != null ) {
								var otherChildren:Array <GSSNode> = mixinList.get(parent).getChildren();
								var lockedProperties:Array <String> = [for ( x in children ) x.name];
								for ( i in 0...otherChildren.length ) {
									var child:GSSNode = otherChildren[i];
									var propName:String = child.name, hasProp:Bool = false;
									for ( x in lockedProperties ) if ( x == propName ) hasProp = true;
									
									if ( !hasProp ) {
										children.push( child );
									}									
								}
							}
						}
					}
					for ( child in children ) node.appendChild( child );
					
					mixinList.set(name, node);
					return node;
					
				//Parametric Mixin ( Function )
				} else {
					var locals:Array <String> = [], funcName:String = next()[1];
					Console.log( "That shit is a function!" );
					var dis:Int = 3;
					while( next(dis)[1] != ")" ) {
						if ( next(dis)[1] != "," ) {
							locals.push(StringTools.ltrim(StringTools.rtrim(next(dis)[1])));
						}
						dis++;
					}
					advance( dis );
					//Console.log( next() );
					
					var brackets:Int = 1, list:Array <Array<String>> = [], dis:Int = 2;
					while( brackets > 0 ) {
						if ( next(dis)[1] == "{" ) brackets++;
						else if ( next(dis)[1] == "}" ) brackets--;
						if (!(next(dis)[1] == "}" && brackets == 0)) {
							list.push( next(dis) );
						}
						dis++;
					}
					advance(dis);
					var children:Array <GSSNode> = parseStyleGroup( list );
					
					//Miniature Lexer for processing property values
					function lexPropertyValue( value:String ) {
						Console.log('Lexing "$value" as Property Value');
						var input:Array <String> = value.split('');
						var pos:Int = 0, c:String = input[pos], tokens:Array <String> = [];
						var advance = function( dis:Int=1 ):Void {
							pos += dis;
							c = input[pos];
						}, next = function( dis:Int ):String {
							return input[pos+dis];
						};
						
						while ( pos < input.length ) {
							c = input[pos];
							
							if ( isWhiteSpace(c) ) advance();
							else if ( isIdentifier(c) ) {
								var d:Int = 1, ident:String = c;
								while( next(d) != null && next(d) != "[" && isIdentifier(next(d)) ) {
									ident += next(d);
									d++;
								}
								if ( next(d) == "[" && ident == "arguments" ) {
									while( next(d) != "]" && next(d) != null ) {
										if(!(isWhiteSpace(next(d)))) ident += next(d);
										d++;
									}
									ident += next(d);
								}
								else if ( next(d) == "(" && ident == "arguments" ) {
									while ( next(d) != ")" && next(d) != null ) {
										if(!isWhiteSpace(next(d))) ident += next(d);
										d++;
									}
								}
								advance(d+1);
								tokens.push(ident);
							}
							
						}
						return tokens;
					}
					
					//Function for handling 'argument' keyword
					function handleArgumentKeyword( value:String, args:Array <String> ) {
						var vals:Array <String> = lexPropertyValue(value);
						value = vals.join(" ");
						Console.log("THESE WERE THE SHIT COCKS I GOT:");
						Console.log( vals );
						var argRef:EReg = ~/arguments/g;
						var argIndice:EReg = ~/arguments(\[(.+)\])/g;
						var argSubset:EReg = ~/arguments\[([0-9]+)?->([0-9]+)?\]/g;
						var argJoiner:EReg = ~/arguments\((["'A-Z0-9]+)\)/g;
						
						for ( _i in 0...vals.length ) {
							var x:String = vals[_i];
							if (argSubset.match(x)) {
								Console.log("THIS APPEARS TO BE AN ARGUMENT SUBSET EXPRESSION");
								Console.log( x );
								var strIndices:String = StringTools.replace(x, "arguments[", "");
								strIndices = StringTools.replace(strIndices, "]", "");
								strIndices = StringTools.replace(strIndices, " ", "");
								var ints:Array <Int> = [for (i in strIndices.split("->")) Std.parseInt(i)];
								if ( ints.length == 2 && ints[1] == 0 ) {
									ints[1] = args.length-1;
								}
								value = StringTools.replace(value, x, (args.slice(ints[0], ints[1])).join(" "));
							}
							else if (argJoiner.match(x)) {
								var joiner:String = StringTools.replace(x, "arguments(", "");
								joiner = StringTools.replace(x, ")", "");
								value = StringTools.replace(value, x, args.join(joiner));
							}
							else if (argIndice.match(x)) {
								var strIndex:String = StringTools.replace(x, "arguments[", "");
								strIndex = StringTools.replace(strIndex, "]", "");
								var index:Int = Std.parseInt(strIndex);
								value = StringTools.replace(value, x, args[index]);
							}
							else if ( argRef.match(x) ) value = StringTools.replace(value, x, args.join(" "));
						}
						return value;
					}
					var node:GSSFunction = new GSSFunction(function( args:Array <String> ):Array <GSSNode> {
						for ( i in 0...args.length ) {
							var arg:String = args[i];
							for ( ix in 0...children.length ) {
								var child:GSSNode = children[ix];
								var val:String = child.value;
								for ( x in 0...locals.length ) val = StringTools.replace(val, locals[x], args[x]);
								val = handleArgumentKeyword( val, args );
								child.setValue( val );
							}
						}
						return children;
					});
					this.functions.set( funcName, node );
					return node;
				}
			}
			//Import Statement
			else if ( type == "keyword" && value == "import" && next()[0] == "string" ) {
				var path:String = next()[1];
				this.gss_import( path );
				advance( 3 );
				var node:GSSNode = new GSSNode( "import" );
				return node;
			}
			//Stream Comment
			else if ( type == "stream_comment" ) {
				var node:GSSNode = new GSSNode( "comment" );
				node.setValue( value );
				advance();
				return node;
			}
			//Block Comment
			else if ( type == "block_comment" ) {
				advance();
				return new GSSNode( "block_comment" );
			}
			else {
				Console.log( nodeTree );
				throw 'Unrecognized token $tk.';
			}
		}
		
		while ( i < tokens.length ) {
			token = tokens[i];
			var curNode:GSSNode = parseToken( token );
			addNode( curNode );
		}
		
		return nodeTree;
	}
	
	public function compile( ast:Array<GSSNode> ):String {
		var css:String = "/*\nGenerated from GSS code using the GSS -> CSS Compiler, written by Ryan Davis.\n*/\n\n";
		for ( node in ast ) {
			if ( node.type == "mixin_declaration" ) node.getValue(this.variables, this.mixins);
			css += node.getValue(this.variables, this.mixins);
		}
		
		return css;
	}
	public function interpret( ast:Array<GSSNode> ):Void {
		for ( node in ast ) {
			node.getValue( this.variables, this.mixins );
		}
	}
	public function gss_import( path:String ):Void {
		var input:String = this.getFile( path )+"";
		Console.log( "Got Import" );
		var gss:GSS = new GSS( this.getFile, true );
		Helpers.bind(gss);
		Builtins.bind(gss);
		var tokens:Array<Array<String>> = gss.lex( input );
		Console.log( "Tokenized Import" );
		var ast:Array <GSSNode> = gss.parse( tokens );
		Console.log( "Parsed Import" );
		gss.interpret( ast );
		Console.log( "Interpreted Import" );
		for ( key in gss.variables.keys ) {
			this.variables.set(key, gss.variables.get(key));
		}
		for ( key in gss.mixins.keys ) {
			this.mixins.set(key, gss.mixins.get(key));
		}
		for ( key in gss.functions.keys ) {
			this.functions.set(key, gss.functions.get(key));
		}
	}
}