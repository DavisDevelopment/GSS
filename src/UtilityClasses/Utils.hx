
class Utils {
	public static function contains( list:Array <Dynamic>, item:Dynamic ):Bool {
		var has:Bool = false;
		for ( x in list ) {
			if ( x == item ) {
				has = true;
				break;
			} else {
				continue;
			}
		}
		return has;
	}
}