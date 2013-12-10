#include <hxcpp.h>

#ifndef INCLUDED_Base64
#include <Base64.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Base64_obj::__construct()
{
	return null();
}

Base64_obj::~Base64_obj() { }

Dynamic Base64_obj::__CreateEmpty() { return  new Base64_obj; }
hx::ObjectPtr< Base64_obj > Base64_obj::__new()
{  hx::ObjectPtr< Base64_obj > result = new Base64_obj();
	result->__construct();
	return result;}

Dynamic Base64_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Base64_obj > result = new Base64_obj();
	result->__construct();
	return result;}

::String Base64_obj::_keyStr;

::String Base64_obj::encode( ::String input){
	HX_STACK_PUSH("Base64::encode","Base64.hx",5);
	HX_STACK_ARG(input,"input");
	HX_STACK_LINE(7)
	::String output = HX_CSTRING("");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(8)
	int chr1;		HX_STACK_VAR(chr1,"chr1");
	int chr2;		HX_STACK_VAR(chr2,"chr2");
	int chr3;		HX_STACK_VAR(chr3,"chr3");
	int enc1;		HX_STACK_VAR(enc1,"enc1");
	int enc2;		HX_STACK_VAR(enc2,"enc2");
	int enc3;		HX_STACK_VAR(enc3,"enc3");
	int enc4;		HX_STACK_VAR(enc4,"enc4");
	HX_STACK_LINE(9)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(11)
	input = ::Base64_obj::_utf8_encode(input);
	HX_STACK_LINE(13)
	while(((i < input.length))){
		HX_STACK_LINE(15)
		chr1 = input.cca((i)++);
		HX_STACK_LINE(16)
		chr2 = input.cca((i)++);
		HX_STACK_LINE(17)
		chr3 = input.cca((i)++);
		HX_STACK_LINE(19)
		enc1 = (int(chr1) >> int((int)2));
		HX_STACK_LINE(20)
		enc2 = (int((int(((int(chr1) & int((int)3)))) << int((int)4))) | int((int(chr2) >> int((int)4))));
		HX_STACK_LINE(21)
		enc3 = (int((int(((int(chr2) & int((int)15)))) << int((int)2))) | int((int(chr3) >> int((int)6))));
		HX_STACK_LINE(22)
		enc4 = (int(chr3) & int((int)63));
		HX_STACK_LINE(24)
		if ((::Math_obj::isNaN(chr2))){
			HX_STACK_LINE(24)
			enc3 = enc4 = (int)64;
		}
		else{
			HX_STACK_LINE(26)
			if ((::Math_obj::isNaN(chr3))){
				HX_STACK_LINE(26)
				enc4 = (int)64;
			}
		}
		HX_STACK_LINE(30)
		output = ((((output + ::Base64_obj::_keyStr.split(HX_CSTRING(""))->__get(enc1)) + ::Base64_obj::_keyStr.split(HX_CSTRING(""))->__get(enc2)) + ::Base64_obj::_keyStr.split(HX_CSTRING(""))->__get(enc3)) + ::Base64_obj::_keyStr.split(HX_CSTRING(""))->__get(enc4));
	}
	HX_STACK_LINE(36)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Base64_obj,encode,return )

::String Base64_obj::_utf8_encode( ::String string){
	HX_STACK_PUSH("Base64::_utf8_encode","Base64.hx",39);
	HX_STACK_ARG(string,"string");
	HX_STACK_LINE(40)
	string = ::StringTools_obj::replace(string,HX_CSTRING("\r\n"),HX_CSTRING("\n"));
	HX_STACK_LINE(41)
	::String utftext = HX_CSTRING("");		HX_STACK_VAR(utftext,"utftext");
	HX_STACK_LINE(43)
	{
		HX_STACK_LINE(43)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = string.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		while(((_g1 < _g))){
			HX_STACK_LINE(43)
			int n = (_g1)++;		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(45)
			int c = string.cca(n);		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(47)
			if (((c < (int)128))){
				HX_STACK_LINE(47)
				hx::AddEq(utftext,::String::fromCharCode(c));
			}
			else{
				HX_STACK_LINE(50)
				if (((bool((c > (int)127)) && bool((c < (int)2048))))){
					HX_STACK_LINE(51)
					hx::AddEq(utftext,::String::fromCharCode((int((int(c) >> int((int)6))) | int((int)192))));
					HX_STACK_LINE(52)
					hx::AddEq(utftext,::String::fromCharCode((int((int(c) & int((int)63))) | int((int)128))));
				}
				else{
					HX_STACK_LINE(55)
					hx::AddEq(utftext,::String::fromCharCode((int((int(c) >> int((int)12))) | int((int)224))));
					HX_STACK_LINE(56)
					hx::AddEq(utftext,::String::fromCharCode((int((int((int(c) >> int((int)6))) & int((int)63))) | int((int)128))));
					HX_STACK_LINE(57)
					hx::AddEq(utftext,::String::fromCharCode((int((int(c) & int((int)63))) | int((int)128))));
				}
			}
		}
	}
	HX_STACK_LINE(62)
	return utftext;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Base64_obj,_utf8_encode,return )

::String Base64_obj::_utf8_decode( ::String utftext){
	HX_STACK_PUSH("Base64::_utf8_decode","Base64.hx",65);
	HX_STACK_ARG(utftext,"utftext");
	HX_STACK_LINE(66)
	::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
	HX_STACK_LINE(67)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(68)
	int c = (int)0;		HX_STACK_VAR(c,"c");
	int c1 = (int)0;		HX_STACK_VAR(c1,"c1");
	int c2 = (int)0;		HX_STACK_VAR(c2,"c2");
	int c3 = (int)0;		HX_STACK_VAR(c3,"c3");
	HX_STACK_LINE(70)
	while(((i < utftext.length))){
		HX_STACK_LINE(72)
		c = utftext.cca(i);
		HX_STACK_LINE(74)
		if (((c < (int)128))){
			HX_STACK_LINE(75)
			hx::AddEq(string,::String::fromCharCode(c));
			HX_STACK_LINE(76)
			(i)++;
		}
		else{
			HX_STACK_LINE(78)
			if (((bool((c > (int)191)) && bool((c < (int)224))))){
				HX_STACK_LINE(79)
				c2 = utftext.cca((i + (int)1));
				HX_STACK_LINE(80)
				hx::AddEq(string,::String::fromCharCode((int((int(((int(c) & int((int)31)))) << int((int)6))) | int((int(c2) & int((int)63))))));
				HX_STACK_LINE(81)
				hx::AddEq(i,(int)2);
			}
			else{
				HX_STACK_LINE(84)
				c2 = utftext.cca((i + (int)1));
				HX_STACK_LINE(85)
				c3 = utftext.cca((i + (int)2));
				HX_STACK_LINE(86)
				hx::AddEq(string,::String::fromCharCode((int((int((int(((int(c) & int((int)15)))) << int((int)12))) | int((int(((int(c2) & int((int)63)))) << int((int)6))))) | int((int(c3) & int((int)63))))));
				HX_STACK_LINE(87)
				hx::AddEq(i,(int)3);
			}
		}
	}
	HX_STACK_LINE(92)
	return string;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Base64_obj,_utf8_decode,return )


Base64_obj::Base64_obj()
{
}

void Base64_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Base64);
	HX_MARK_END_CLASS();
}

void Base64_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Base64_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_keyStr") ) { return _keyStr; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_utf8_encode") ) { return _utf8_encode_dyn(); }
		if (HX_FIELD_EQ(inName,"_utf8_decode") ) { return _utf8_decode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Base64_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_keyStr") ) { _keyStr=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Base64_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_keyStr"),
	HX_CSTRING("encode"),
	HX_CSTRING("_utf8_encode"),
	HX_CSTRING("_utf8_decode"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Base64_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Base64_obj::_keyStr,"_keyStr");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Base64_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Base64_obj::_keyStr,"_keyStr");
};

Class Base64_obj::__mClass;

void Base64_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Base64"), hx::TCanCast< Base64_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Base64_obj::__boot()
{
	_keyStr= HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=");
}

