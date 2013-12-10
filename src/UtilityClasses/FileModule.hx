
@:expose class FileModule {

	public static function joinPaths( pathList:Array <String> ):String {
		var path:String = "";
		for ( i in 0...pathList.length ) {
			var p:String = pathList[i];
			path += StringTools.replace(p, "\\", "/");
			if ( path.substring(path.length-2, path.length-1) != "/" && i != pathList.length-1 ) path += "/";
		}
		return path;
	}
	public static function getExtension( path:String ):String {
		return path.substring( path.lastIndexOf("."), path.length );
	}
	public static function getDirectoryName( rawPath:String ):String {
		var path:String = StringTools.replace(rawPath, "\\", "/");
		return path.substring( 0, path.lastIndexOf("/")+1 );
	}
	public static dynamic function getContent( path:String ):String {
		#if (cpp || neko || php)
		return sys.io.File.getContent( path );
		#end
		return "";
	}
	public static dynamic function Exists( path:String ):Bool {
		#if (cpp || neko || php)
		return sys.FileSystem.exists( path );
		#end
		return true;
	}
	public static function toDataURL( content:String, mime_type:String ):String {
		var encodedData:String = Base64.encode( content );
		return 'data:$mime_type;base64,$encodedData';
	}
	public static function getMimeType( path:String ):String {
		var fileExtensions:Array <String> = [
			".jpg", ".jpeg", ".png", ".bmp", ".gif", ".svg"
		];
		var mimeTypes:Array <String> = [
			"image/jpeg", "image/jpeg", "image/png", "image/bmp", "image/gif", "image/svg+xml"
		];
		var mimeTypeGetter:Mapper <String, String> = new Mapper( fileExtensions, mimeTypes );
		var extension:String = getExtension(path);
		return (mimeTypeGetter.get(extension) != null) ? mimeTypeGetter.get(extension) : "applicaton/octet-stream";
	}
}