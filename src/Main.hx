
class Main {
	public static function main() {
		//Here, we either expose the GSS Object in the Global Namespace, or process a file input.
		#if js
			GSS;
			Helpers;
			trace("GSS Ready");
			FileModule.getContent = JSFileModule.getContent;
			FileModule.Exists = JSFileModule.Exists;
		#elseif cpp
			var args:Array <String> = Sys.args();
			var __path__:String = "";
			var input:String = "", cwd:String = Sys.getCwd();
			if ( args.length >= 1 ) {
				var initPath:String = args[0];
				var path = StringTools.replace((cwd + initPath), "\\", "/");
				__path__ = path;
				if ( sys.FileSystem.exists(path) ) {
					input = sys.io.File.getContent(path);
				} else {
					throw 'IOError: Could not find file $path.';
				}
			} 
			else {
				input = ".element { padding: 14px; margin: 20px; width:  960px; }";
			}
			//GSS Object's 'getFile' function
			function getFile( initPath:String ):String {
				var broken:Array<String> = __path__.split("/");
				var dirPath:String = broken.slice(0, broken.length-1).join("/");
				var path:String = StringTools.replace((dirPath+"/"+initPath), "\\", "/");
				trace( "Importing File From:" );
				trace( path );
				if ( sys.FileSystem.exists(path) ) {
					var content:String = sys.io.File.getContent( path );
					trace( content );
					return content;
				} else {
					throw 'ImportError:  Could not \'import\' $initPath from $dirPath.';
				}
			}
			var gss:GSS = new GSS( getFile, __path__, true );			
			Helpers.bind( gss );
			Builtins.bind( gss );
			var tokens:Array<Array<String>> = gss.lex( input );
			trace( tokens );
			var ast:Array<GSSNode> = gss.parse( tokens );
			trace( ast );
			var css:String = gss.compile( ast );
			if ( args.length == 1 ) {
				trace( css );
			} 
			else if ( args.length == 2 ) {
				var initPath:String = args[1], writePath:String = StringTools.replace((cwd+initPath), "\\", "/");
				sys.io.File.saveContent( writePath, css );
			}
		#end
	}
}