#include <hxcpp.h>

#ifndef INCLUDED_Builtins
#include <Builtins.h>
#endif
#ifndef INCLUDED_GSS
#include <GSS.h>
#endif
#ifndef INCLUDED_GSSNode
#include <GSSNode.h>
#endif

Void Builtins_obj::__construct()
{
	return null();
}

Builtins_obj::~Builtins_obj() { }

Dynamic Builtins_obj::__CreateEmpty() { return  new Builtins_obj; }
hx::ObjectPtr< Builtins_obj > Builtins_obj::__new()
{  hx::ObjectPtr< Builtins_obj > result = new Builtins_obj();
	result->__construct();
	return result;}

Dynamic Builtins_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Builtins_obj > result = new Builtins_obj();
	result->__construct();
	return result;}

Void Builtins_obj::bind( ::GSS gss){
{
		HX_STACK_PUSH("Builtins::bind","Builtins.hx",3);
		HX_STACK_ARG(gss,"gss");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Array< ::Dynamic > run(Array< ::String > args){
			HX_STACK_PUSH("*::_Function_1_1","Builtins.hx",4);
			HX_STACK_ARG(args,"args");
			{
				HX_STACK_LINE(5)
				Array< ::Dynamic > nodes = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(nodes,"nodes");
				HX_STACK_LINE(6)
				::String mode = args->__get((int)0);		HX_STACK_VAR(mode,"mode");
				HX_STACK_LINE(7)
				Array< ::Dynamic > txtNodes = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(txtNodes,"txtNodes");
				HX_STACK_LINE(8)
				if (((mode == HX_CSTRING("text")))){
					HX_STACK_LINE(8)
					txtNodes = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::String >::__new().Add(HX_CSTRING("text-align")).Add(HX_CSTRING("center")));
				}
				else{
					HX_STACK_LINE(13)
					if (((mode == HX_CSTRING("block")))){
						HX_STACK_LINE(13)
						txtNodes = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::String >::__new().Add(HX_CSTRING("display")).Add(HX_CSTRING("block"))).Add(Array_obj< ::String >::__new().Add(HX_CSTRING("margin-left")).Add(HX_CSTRING("auto"))).Add(Array_obj< ::String >::__new().Add(HX_CSTRING("margin-right")).Add(HX_CSTRING("auto")));
					}
				}
				HX_STACK_LINE(20)
				{
					HX_STACK_LINE(20)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(20)
					while(((_g < txtNodes->length))){
						HX_STACK_LINE(20)
						Array< ::String > item = txtNodes->__get(_g).StaticCast< Array< ::String > >();		HX_STACK_VAR(item,"item");
						HX_STACK_LINE(20)
						++(_g);
						HX_STACK_LINE(21)
						::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("prop_assignment"));		HX_STACK_VAR(node,"node");
						HX_STACK_LINE(22)
						node->setName(item->__get((int)0));
						HX_STACK_LINE(23)
						node->setValue(item->__get((int)1));
						HX_STACK_LINE(24)
						nodes->push(node);
					}
				}
				HX_STACK_LINE(27)
				return nodes;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(3)
		gss->_register(HX_CSTRING("center"), Dynamic(new _Function_1_1()));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Builtins_obj,bind,(void))


Builtins_obj::Builtins_obj()
{
}

void Builtins_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Builtins);
	HX_MARK_END_CLASS();
}

void Builtins_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Builtins_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Builtins_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Builtins_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("bind"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Builtins_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Builtins_obj::__mClass,"__mClass");
};

Class Builtins_obj::__mClass;

void Builtins_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Builtins"), hx::TCanCast< Builtins_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Builtins_obj::__boot()
{
}

