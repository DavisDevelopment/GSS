
@:expose class Builtins {
	public static function bind( gss:GSS ) {
		gss.register("center", function( args:Array <String> ):Array <GSSNode> {
			var nodes:Array <GSSNode> = [];
			var mode:String = args[0];
			var txtNodes:Array <Array<String>> = [];
			if ( mode == "text" ) {
				txtNodes = [
					["text-align", "center"]
				];
			}
			else if ( mode == "block" ) {
				txtNodes = [
					["display", "block"],
					["margin-left", "auto"],
					["margin-right", "auto"]
				];
			}
			for ( item in txtNodes ) {
				var node:GSSNode = new GSSNode( "prop_assignment" );
				node.setName(item[0]);
				node.setValue(item[1]);
				nodes.push(node);
			}
			
			return nodes;
		});
	}
}