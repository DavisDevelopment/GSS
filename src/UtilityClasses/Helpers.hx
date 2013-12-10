
@:expose class Helpers {
	//Function that binds all helper functions into the GSS global namespace
	public static function bind( gss:GSS ):Void {
		inline function breakPath( p:String ):Array <String> {
			return p.split("/");
		}
		
		//rgb function:  converts rgb colors to HEX notation
		gss.helper("rgb", function( args:Array <String> ):String {
			var r:Int = Std.parseInt(args[0]), g:Int = Std.parseInt(args[1]), b:Int = Std.parseInt(args[1]);
			return Color.hexToRgb(r, g, b);
		});
		
		//url function:  Uses dataURL's to inline assets
		gss.helper("url", function( args:Array <String> ):String {
			var rawPath:String = args[0];
			var broken:Array<String> = breakPath(gss.__dir__);
			var path:String = FileModule.joinPaths([(broken.slice(0, broken.length-1).join("/")), rawPath]);
			return 'url(\"$rawPath\")';
		});
		
		//format function:  Takes a template string as it's first argument, and the rest of the arguments replace the template nodes sequentially
		gss.helper("format", function( args:Array <String> ):String {
			var template:String = args[0], values:Array <String> = args.slice(1, args.length);
			var ret:String = template;
			
			for ( i in 0...values.length ) {
				var val:String = values[i];
				ret = StringTools.replace(ret, '{$i}', val);
			}
			
			return ret;
		});
	}
}