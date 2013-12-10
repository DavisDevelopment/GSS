#include <hxcpp.h>

#ifndef INCLUDED_Color
#include <Color.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

Void Color_obj::__construct()
{
	return null();
}

Color_obj::~Color_obj() { }

Dynamic Color_obj::__CreateEmpty() { return  new Color_obj; }
hx::ObjectPtr< Color_obj > Color_obj::__new()
{  hx::ObjectPtr< Color_obj > result = new Color_obj();
	result->__construct();
	return result;}

Dynamic Color_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Color_obj > result = new Color_obj();
	result->__construct();
	return result;}

::String Color_obj::hexToRgb( int r,int g,int b){
	HX_STACK_PUSH("Color::hexToRgb","Color.hx",3);
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(4)
	::String R = ::StringTools_obj::hex(r,(int)2);		HX_STACK_VAR(R,"R");
	HX_STACK_LINE(5)
	::String G = ::StringTools_obj::hex(g,(int)2);		HX_STACK_VAR(G,"G");
	HX_STACK_LINE(6)
	::String B = ::StringTools_obj::hex(b,(int)2);		HX_STACK_VAR(B,"B");
	HX_STACK_LINE(7)
	return (((HX_CSTRING("#") + R) + G) + B);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Color_obj,hexToRgb,return )


Color_obj::Color_obj()
{
}

void Color_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Color);
	HX_MARK_END_CLASS();
}

void Color_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Color_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"hexToRgb") ) { return hexToRgb_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Color_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Color_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("hexToRgb"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Color_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Color_obj::__mClass,"__mClass");
};

Class Color_obj::__mClass;

void Color_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Color"), hx::TCanCast< Color_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Color_obj::__boot()
{
}

