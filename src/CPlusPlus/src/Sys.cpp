#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void Sys_obj::__construct()
{
	return null();
}

Sys_obj::~Sys_obj() { }

Dynamic Sys_obj::__CreateEmpty() { return  new Sys_obj; }
hx::ObjectPtr< Sys_obj > Sys_obj::__new()
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Dynamic Sys_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Array< ::String > Sys_obj::args( ){
	HX_STACK_PUSH("Sys::args","C:\\HaxeToolkit\\haxe/std/cpp/_std/Sys.hx",49);
	HX_STACK_LINE(49)
	return ::__get_args();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,args,return )

::String Sys_obj::getCwd( ){
	HX_STACK_PUSH("Sys::getCwd","C:\\HaxeToolkit\\haxe/std/cpp/_std/Sys.hx",72);
	HX_STACK_LINE(72)
	return ::String(::Sys_obj::get_cwd());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,getCwd,return )

Dynamic Sys_obj::get_cwd;


Sys_obj::Sys_obj()
{
}

void Sys_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sys);
	HX_MARK_END_CLASS();
}

void Sys_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Sys_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"getCwd") ) { return getCwd_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_cwd") ) { return get_cwd; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sys_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"get_cwd") ) { get_cwd=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sys_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("args"),
	HX_CSTRING("getCwd"),
	HX_CSTRING("get_cwd"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Sys_obj::get_cwd,"get_cwd");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Sys_obj::get_cwd,"get_cwd");
};

Class Sys_obj::__mClass;

void Sys_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Sys"), hx::TCanCast< Sys_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Sys_obj::__boot()
{
	get_cwd= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("get_cwd"),(int)0);
}

