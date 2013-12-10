#include <hxcpp.h>

#ifndef INCLUDED_GSSHelper
#include <GSSHelper.h>
#endif
#ifndef INCLUDED_GSSNode
#include <GSSNode.h>
#endif

Void GSSHelper_obj::__construct(Dynamic rawFunc)
{
HX_STACK_PUSH("GSSHelper::new","GSSHelper.hx",4);
{
	HX_STACK_LINE(5)
	super::__construct(HX_CSTRING("helper_function"));
	HX_STACK_LINE(6)
	this->func = rawFunc;
}
;
	return null();
}

GSSHelper_obj::~GSSHelper_obj() { }

Dynamic GSSHelper_obj::__CreateEmpty() { return  new GSSHelper_obj; }
hx::ObjectPtr< GSSHelper_obj > GSSHelper_obj::__new(Dynamic rawFunc)
{  hx::ObjectPtr< GSSHelper_obj > result = new GSSHelper_obj();
	result->__construct(rawFunc);
	return result;}

Dynamic GSSHelper_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GSSHelper_obj > result = new GSSHelper_obj();
	result->__construct(inArgs[0]);
	return result;}

::String GSSHelper_obj::__call__( Array< ::String > args){
	HX_STACK_PUSH("GSSHelper::__call__","GSSHelper.hx",9);
	HX_STACK_THIS(this);
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(9)
	return this->func(args);
}


HX_DEFINE_DYNAMIC_FUNC1(GSSHelper_obj,__call__,return )


GSSHelper_obj::GSSHelper_obj()
{
}

void GSSHelper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GSSHelper);
	HX_MARK_MEMBER_NAME(func,"func");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GSSHelper_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(func,"func");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GSSHelper_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"func") ) { return func; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__call__") ) { return __call___dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GSSHelper_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"func") ) { func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GSSHelper_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__call__"),
	HX_CSTRING("func"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GSSHelper_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GSSHelper_obj::__mClass,"__mClass");
};

Class GSSHelper_obj::__mClass;

void GSSHelper_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GSSHelper"), hx::TCanCast< GSSHelper_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GSSHelper_obj::__boot()
{
}

