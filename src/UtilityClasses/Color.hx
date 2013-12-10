
class Color {
	public static function hexToRgb( r:Int, g:Int, b:Int ):String {
		var R:String = StringTools.hex(r, 2);
		var G:String = StringTools.hex(g, 2);
		var B:String = StringTools.hex(b, 2);
		return '#$R$G$B';
	}
}