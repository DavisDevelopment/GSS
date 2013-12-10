
class GSSFunction extends GSSNode {
	private var func:Array<String> -> Array<GSSNode>;
	public function new( func:Array<String> -> Array<GSSNode> ) {
		super( "function" );
		this.func = func;
	}
	public function __call__( args:Array<String> ):Array<GSSNode> {
		return this.func( args );
	}
}