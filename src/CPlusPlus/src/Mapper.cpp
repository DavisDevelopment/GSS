#include <hxcpp.h>

#ifndef INCLUDED_Mapper
#include <Mapper.h>
#endif

Void Mapper_obj::__construct(Dynamic ks,Dynamic vs)
{
HX_STACK_PUSH("Mapper::new","Mapper.hx",6);
{
	HX_STACK_LINE(7)
	this->keys = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(8)
	this->values = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(9)
	if (((bool((ks != null())) && bool((vs != null()))))){
		HX_STACK_LINE(9)
		if (((ks->__Field(HX_CSTRING("length"),true) == vs->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(11)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ks->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(11)
			while(((_g1 < _g))){
				HX_STACK_LINE(11)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(12)
				this->keys->__Field(HX_CSTRING("push"),true)(ks->__GetItem(i));
				HX_STACK_LINE(13)
				this->values->__Field(HX_CSTRING("push"),true)(vs->__GetItem(i));
			}
		}
	}
}
;
	return null();
}

Mapper_obj::~Mapper_obj() { }

Dynamic Mapper_obj::__CreateEmpty() { return  new Mapper_obj; }
hx::ObjectPtr< Mapper_obj > Mapper_obj::__new(Dynamic ks,Dynamic vs)
{  hx::ObjectPtr< Mapper_obj > result = new Mapper_obj();
	result->__construct(ks,vs);
	return result;}

Dynamic Mapper_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mapper_obj > result = new Mapper_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Mapper_obj::extend( ::Mapper other){
{
		HX_STACK_PUSH("Mapper::extend","Mapper.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_ARG(other,"other");
		HX_STACK_LINE(43)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Dynamic _g1 = other->keys;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(43)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(43)
			Dynamic key = _g1->__GetItem(_g);		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(43)
			++(_g);
			HX_STACK_LINE(44)
			this->set(key,other->get(key));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mapper_obj,extend,(void))

Dynamic Mapper_obj::get( Dynamic key){
	HX_STACK_PUSH("Mapper::get","Mapper.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(31)
	Dynamic ret = null();		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(32)
	{
		HX_STACK_LINE(32)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->keys->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		while(((_g1 < _g))){
			HX_STACK_LINE(32)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(33)
			Dynamic k = this->keys->__GetItem(i);		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(34)
			if (((k == key))){
				HX_STACK_LINE(35)
				ret = this->values->__GetItem(i);
				HX_STACK_LINE(36)
				break;
			}
		}
	}
	HX_STACK_LINE(39)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(Mapper_obj,get,return )

Void Mapper_obj::set( Dynamic key,Dynamic value){
{
		HX_STACK_PUSH("Mapper::set","Mapper.hx",19);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(19)
		if (((this->get(key) != null()))){
			HX_STACK_LINE(21)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->keys->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(21)
			while(((_g1 < _g))){
				HX_STACK_LINE(21)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(22)
				if (((this->keys->__GetItem(i) == key))){
					HX_STACK_LINE(22)
					hx::IndexRef((this->values).mPtr,i) = value;
				}
			}
		}
		else{
			HX_STACK_LINE(25)
			this->keys->__Field(HX_CSTRING("push"),true)(key);
			HX_STACK_LINE(26)
			this->values->__Field(HX_CSTRING("push"),true)(value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Mapper_obj,set,(void))


Mapper_obj::Mapper_obj()
{
}

void Mapper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mapper);
	HX_MARK_MEMBER_NAME(values,"values");
	HX_MARK_MEMBER_NAME(keys,"keys");
	HX_MARK_END_CLASS();
}

void Mapper_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(values,"values");
	HX_VISIT_MEMBER_NAME(keys,"keys");
}

Dynamic Mapper_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"extend") ) { return extend_dyn(); }
		if (HX_FIELD_EQ(inName,"values") ) { return values; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mapper_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { keys=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"values") ) { values=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mapper_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("values"));
	outFields->push(HX_CSTRING("keys"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("extend"),
	HX_CSTRING("get"),
	HX_CSTRING("set"),
	HX_CSTRING("values"),
	HX_CSTRING("keys"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mapper_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mapper_obj::__mClass,"__mClass");
};

Class Mapper_obj::__mClass;

void Mapper_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Mapper"), hx::TCanCast< Mapper_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Mapper_obj::__boot()
{
}

