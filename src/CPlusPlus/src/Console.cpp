#include <hxcpp.h>

#ifndef INCLUDED_Console
#include <Console.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Console_obj::__construct()
{
	return null();
}

Console_obj::~Console_obj() { }

Dynamic Console_obj::__CreateEmpty() { return  new Console_obj; }
hx::ObjectPtr< Console_obj > Console_obj::__new()
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

Dynamic Console_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

Void Console_obj::log( Dynamic x){
{
		HX_STACK_PUSH("Console::log","GSS.hx",3);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(4)
		bool debug = false;		HX_STACK_VAR(debug,"debug");
		HX_STACK_LINE(5)
		if ((debug)){
			HX_STACK_LINE(5)
			::haxe::Log_obj::trace(x,hx::SourceInfo(HX_CSTRING("GSS.hx"),5,HX_CSTRING("Console"),HX_CSTRING("log")));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,log,(void))


Console_obj::Console_obj()
{
}

void Console_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Console);
	HX_MARK_END_CLASS();
}

void Console_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Console_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { return log_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Console_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Console_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("log"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Console_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Console_obj::__mClass,"__mClass");
};

Class Console_obj::__mClass;

void Console_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Console"), hx::TCanCast< Console_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Console_obj::__boot()
{
}

