
class Mapper<K, V> {
	public var keys:Array<K>;
	private var values:Array<V>;
	
	public function new( ?ks:Array<K>, ?vs:Array<V> ) {
		this.keys = [];
		this.values = [];
		if ( ks != null && vs != null ) {
			if ( ks.length == vs.length ) {
				for ( i in 0...ks.length ) {
					this.keys.push(ks[i]);
					this.values.push(vs[i]);
				}
			}
		}
	}
	
	public function set( key:K, value:V ):Void {
		if ( this.get(key) != null ) {
			for ( i in 0...this.keys.length ) {
				if ( this.keys[i] == key ) this.values[i] = value;
			}
		} else {
			this.keys.push( key );
			this.values.push( value );
		}
	}
	
	public function get( key:K ):Dynamic {
		var ret = null;
		for ( i in 0...this.keys.length ) {
			var k:K = this.keys[i];
			if ( k == key ) {
				ret = this.values[i];
				break;
			}
		}
		return ret;
	}
	
	public function extend( other:Mapper<K,V> ) {
		for ( key in other.keys ) {
			this.set(key, other.get(key));
		}
	}
}