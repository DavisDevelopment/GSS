
class Base64 {
	private static var _keyStr:String = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	
	public static function encode( input:String ):String {
	
        var output:String = "";
        var chr1:Int, chr2:Int, chr3:Int, enc1:Int, enc2:Int, enc3:Int, enc4:Int;
        var i = 0;
 
        input = Base64._utf8_encode(input);
 
        while (i < input.length) {
 
            chr1 = StringTools.fastCodeAt(input, i++);
            chr2 = StringTools.fastCodeAt(input, i++);
            chr3 = StringTools.fastCodeAt(input, i++);
 
            enc1 = chr1 >> 2;
            enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
            enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
            enc4 = chr3 & 63;
 
            if (Math.isNaN(chr2)) {
                enc3 = enc4 = 64;
            } else if (Math.isNaN(chr3)) {
                enc4 = 64;
            }
 
            output = output +
            _keyStr.split('')[enc1] + _keyStr.split('')[enc2] +
            _keyStr.split('')[enc3] + _keyStr.split('')[enc4];
 
        }
 
        return output;
	}
	
	private static function _utf8_encode( string:String ):String {
        string = StringTools.replace(string, "\r\n", "\n");
        var utftext:String = "";
 
        for ( n in 0...string.length ) {
 
            var c:Int = StringTools.fastCodeAt(string, n);
 
            if (c < 128) {
                utftext += String.fromCharCode(c);
            }
            else if((c > 127) && (c < 2048)) {
                utftext += String.fromCharCode((c >> 6) | 192);
                utftext += String.fromCharCode((c & 63) | 128);
            }
            else {
                utftext += String.fromCharCode((c >> 12) | 224);
                utftext += String.fromCharCode(((c >> 6) & 63) | 128);
                utftext += String.fromCharCode((c & 63) | 128);
            }
 
        }
 
        return utftext;
	}
	
	private static function _utf8_decode( utftext:String ):String {
        var string:String = "";
        var i:Int = 0;
        var c:Int = 0, c1:Int = 0, c2:Int = 0, c3:Int = 0;
 
        while ( i < utftext.length ) {
 
            c = StringTools.fastCodeAt(utftext, i);
 
            if (c < 128) {
                string += String.fromCharCode(c);
                i++;
            }
            else if((c > 191) && (c < 224)) {
                c2 = StringTools.fastCodeAt(utftext, i+1);
                string += String.fromCharCode(((c & 31) << 6) | (c2 & 63));
                i += 2;
            }
            else {
                c2 = StringTools.fastCodeAt(utftext, i+1);
                c3 = StringTools.fastCodeAt(utftext, i+2);
                string += String.fromCharCode(((c & 15) << 12) | ((c2 & 63) << 6) | (c3 & 63));
                i += 3;
            }
 
        }
 
        return string;
	}
}