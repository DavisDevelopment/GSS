#include <hxcpp.h>

#ifndef INCLUDED_GSSFunction
#include <GSSFunction.h>
#endif
#ifndef INCLUDED_GSSNode
#include <GSSNode.h>
#endif

Void GSSFunction_obj::__construct(Dynamic func)
{
HX_STACK_PUSH("GSSFunction::new","GSSFunction.hx",4);
{
	HX_STACK_LINE(5)
	super::__construct(HX_CSTRING("function"));
	HX_STACK_LINE(6)
	this->func = func;
}
;
	return null();
}

GSSFunction_obj::~GSSFunction_obj() { }

Dynamic GSSFunction_obj::__CreateEmpty() { return  new GSSFunction_obj; }
hx::ObjectPtr< GSSFunction_obj > GSSFunction_obj::__new(Dynamic func)
{  hx::ObjectPtr< GSSFunction_obj > result = new GSSFunction_obj();
	result->__construct(func);
	return result;}

Dynamic GSSFunction_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GSSFunction_obj > result = new GSSFunction_obj();
	result->__construct(inArgs[0]);
	return result;}

Array< ::Dynamic > GSSFunction_obj::__call__( Array< ::String > args){
	HX_STACK_PUSH("GSSFunction::__call__","GSSFunction.hx",8);
	HX_STACK_THIS(this);
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(8)
	return this->func(args);
}


HX_DEFINE_DYNAMIC_FUNC1(GSSFunction_obj,__call__,return )


GSSFunction_obj::GSSFunction_obj()
{
}

void GSSFunction_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GSSFunction);
	HX_MARK_MEMBER_NAME(func,"func");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GSSFunction_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(func,"func");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GSSFunction_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic GSSFunction_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"func") ) { func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GSSFunction_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(GSSFunction_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GSSFunction_obj::__mClass,"__mClass");
};

Class GSSFunction_obj::__mClass;

void GSSFunction_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GSSFunction"), hx::TCanCast< GSSFunction_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GSSFunction_obj::__boot()
{
}

