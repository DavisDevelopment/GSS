#include <hxcpp.h>

#ifndef INCLUDED_Color
#include <Color.h>
#endif
#ifndef INCLUDED_FileModule
#include <FileModule.h>
#endif
#ifndef INCLUDED_GSS
#include <GSS.h>
#endif
#ifndef INCLUDED_Helpers
#include <Helpers.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

Void Helpers_obj::__construct()
{
	return null();
}

Helpers_obj::~Helpers_obj() { }

Dynamic Helpers_obj::__CreateEmpty() { return  new Helpers_obj; }
hx::ObjectPtr< Helpers_obj > Helpers_obj::__new()
{  hx::ObjectPtr< Helpers_obj > result = new Helpers_obj();
	result->__construct();
	return result;}

Dynamic Helpers_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Helpers_obj > result = new Helpers_obj();
	result->__construct();
	return result;}

Void Helpers_obj::bind( ::GSS gss){
{
		HX_STACK_PUSH("Helpers::bind","Helpers.hx",4);
		HX_STACK_ARG(gss,"gss");
		HX_STACK_LINE(4)
		Array< ::Dynamic > gss1 = Array_obj< ::Dynamic >::__new().Add(gss);		HX_STACK_VAR(gss1,"gss1");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		::String run(Array< ::String > args){
			HX_STACK_PUSH("*::_Function_1_1","Helpers.hx",10);
			HX_STACK_ARG(args,"args");
			{
				HX_STACK_LINE(11)
				int r = ::Std_obj::parseInt(args->__get((int)0));		HX_STACK_VAR(r,"r");
				int g = ::Std_obj::parseInt(args->__get((int)1));		HX_STACK_VAR(g,"g");
				int b = ::Std_obj::parseInt(args->__get((int)1));		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(12)
				return ::Color_obj::hexToRgb(r,g,b);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(10)
		gss1->__get((int)0).StaticCast< ::GSS >()->helper(HX_CSTRING("rgb"), Dynamic(new _Function_1_1()));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,gss1)
		::String run(Array< ::String > args){
			HX_STACK_PUSH("*::_Function_1_2","Helpers.hx",16);
			HX_STACK_ARG(args,"args");
			{
				HX_STACK_LINE(17)
				::String rawPath = args->__get((int)0);		HX_STACK_VAR(rawPath,"rawPath");
				HX_STACK_LINE(18)
				Array< ::String > broken = gss1->__get((int)0).StaticCast< ::GSS >()->__dir__.split(HX_CSTRING("/"));		HX_STACK_VAR(broken,"broken");
				HX_STACK_LINE(19)
				::String path = ::FileModule_obj::joinPaths(Array_obj< ::String >::__new().Add(broken->slice((int)0,(broken->length - (int)1))->join(HX_CSTRING("/"))).Add(rawPath));		HX_STACK_VAR(path,"path");
				HX_STACK_LINE(20)
				return ((HX_CSTRING("url(\"") + rawPath) + HX_CSTRING("\")"));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(16)
		gss1->__get((int)0).StaticCast< ::GSS >()->helper(HX_CSTRING("url"), Dynamic(new _Function_1_2(gss1)));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
		::String run(Array< ::String > args){
			HX_STACK_PUSH("*::_Function_1_3","Helpers.hx",24);
			HX_STACK_ARG(args,"args");
			{
				HX_STACK_LINE(25)
				::String _template = args->__get((int)0);		HX_STACK_VAR(_template,"template");
				Array< ::String > values = args->slice((int)1,args->length);		HX_STACK_VAR(values,"values");
				HX_STACK_LINE(26)
				::String ret = _template;		HX_STACK_VAR(ret,"ret");
				HX_STACK_LINE(28)
				{
					HX_STACK_LINE(28)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = values->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(28)
					while(((_g1 < _g))){
						HX_STACK_LINE(28)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(29)
						::String val = values->__get(i);		HX_STACK_VAR(val,"val");
						HX_STACK_LINE(30)
						ret = ::StringTools_obj::replace(ret,((HX_CSTRING("{") + i) + HX_CSTRING("}")),val);
					}
				}
				HX_STACK_LINE(33)
				return ret;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(24)
		gss1->__get((int)0).StaticCast< ::GSS >()->helper(HX_CSTRING("format"), Dynamic(new _Function_1_3()));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Helpers_obj,bind,(void))


Helpers_obj::Helpers_obj()
{
}

void Helpers_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Helpers);
	HX_MARK_END_CLASS();
}

void Helpers_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Helpers_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Helpers_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Helpers_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("bind"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Helpers_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Helpers_obj::__mClass,"__mClass");
};

Class Helpers_obj::__mClass;

void Helpers_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Helpers"), hx::TCanCast< Helpers_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Helpers_obj::__boot()
{
}

