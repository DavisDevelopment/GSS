
class GSSHelper extends GSSNode {
	private var func:Array <String> -> String;
	public function new( rawFunc:Array <String> -> String ) {
		super( "helper_function" );
		this.func = rawFunc;
	}
	
	public function __call__( args:Array <String> ):String {
		return this.func( args );
	}
}