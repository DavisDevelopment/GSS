#include <hxcpp.h>

#ifndef INCLUDED_GSSNode
#include <GSSNode.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Mapper
#include <Mapper.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

Void GSSNode_obj::__construct(::String type)
{
HX_STACK_PUSH("GSSNode::new","GSSNode.hx",1);
{
	HX_STACK_LINE(5)
	this->indents = (int)4;
	HX_STACK_LINE(12)
	this->type = type;
	HX_STACK_LINE(13)
	this->childNodes = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(14)
	this->toAppendAfter = Array_obj< ::String >::__new();
	HX_STACK_LINE(15)
	this->hasParent = false;
}
;
	return null();
}

GSSNode_obj::~GSSNode_obj() { }

Dynamic GSSNode_obj::__CreateEmpty() { return  new GSSNode_obj; }
hx::ObjectPtr< GSSNode_obj > GSSNode_obj::__new(::String type)
{  hx::ObjectPtr< GSSNode_obj > result = new GSSNode_obj();
	result->__construct(type);
	return result;}

Dynamic GSSNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GSSNode_obj > result = new GSSNode_obj();
	result->__construct(inArgs[0]);
	return result;}

Array< ::Dynamic > GSSNode_obj::getChildren( ){
	HX_STACK_PUSH("GSSNode::getChildren","GSSNode.hx",192);
	HX_STACK_THIS(this);
	HX_STACK_LINE(192)
	return this->childNodes;
}


HX_DEFINE_DYNAMIC_FUNC0(GSSNode_obj,getChildren,return )

::String GSSNode_obj::getValue( ::Mapper variables,::Mapper mixins){
	HX_STACK_PUSH("GSSNode::getValue","GSSNode.hx",63);
	HX_STACK_THIS(this);
	HX_STACK_ARG(variables,"variables");
	HX_STACK_ARG(mixins,"mixins");
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","GSSNode.hx",64);
			{
				HX_STACK_LINE(64)
				Dynamic getFullSelectorString = Dynamic( Array_obj<Dynamic>::__new().Add(null()));		HX_STACK_VAR(getFullSelectorString,"getFullSelectorString");

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,getFullSelectorString)
				::String run(::GSSNode obj){
					HX_STACK_PUSH("*::_Function_2_1","GSSNode.hx",64);
					HX_STACK_ARG(obj,"obj");
					{
						HX_STACK_LINE(65)
						Array< ::String > selectorList = Array_obj< ::String >::__new();		HX_STACK_VAR(selectorList,"selectorList");
						HX_STACK_LINE(66)
						if (((bool((obj->type == HX_CSTRING("selector"))) || bool((obj->type == HX_CSTRING("when_pseudo")))))){
							HX_STACK_LINE(67)
							selectorList->push(obj->value);
							HX_STACK_LINE(68)
							if ((obj->hasParent)){
								HX_STACK_LINE(68)
								selectorList->push(getFullSelectorString->__GetItem((int)0)(obj->parent).Cast< ::String >());
							}
						}
						HX_STACK_LINE(72)
						selectorList->reverse();
						HX_STACK_LINE(73)
						::String selector = selectorList->join(HX_CSTRING(" "));		HX_STACK_VAR(selector,"selector");
						HX_STACK_LINE(74)
						return selector;
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_STACK_LINE(64)
				hx::IndexRef((getFullSelectorString).mPtr,(int)0) =  Dynamic(new _Function_2_1(getFullSelectorString));
				HX_STACK_LINE(64)
				return getFullSelectorString->__GetItem((int)0);
			}
			return null();
		}
	};
	HX_STACK_LINE(64)
	Dynamic getFullSelectorString = _Function_1_1::Block();		HX_STACK_VAR(getFullSelectorString,"getFullSelectorString");
	HX_STACK_LINE(76)
	if (((this->type == HX_CSTRING("selector")))){
		HX_STACK_LINE(77)
		::String selector = getFullSelectorString(hx::ObjectPtr<OBJ_>(this)).Cast< ::String >();		HX_STACK_VAR(selector,"selector");
		HX_STACK_LINE(78)
		::String val = ((HX_CSTRING("") + selector) + HX_CSTRING(" {\n"));		HX_STACK_VAR(val,"val");
		HX_STACK_LINE(79)
		{
			HX_STACK_LINE(79)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::Dynamic > _g1 = this->childNodes;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(79)
			while(((_g < _g1->length))){
				HX_STACK_LINE(79)
				::GSSNode child = _g1->__get(_g).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(79)
				++(_g);
				HX_STACK_LINE(80)
				if (((bool((child->type == HX_CSTRING("prop_assignment"))) || bool((child->type == HX_CSTRING("mixin_reference")))))){
					HX_STACK_LINE(81)
					if (((child->type == HX_CSTRING("mixin_reference")))){
						HX_STACK_LINE(81)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						Array< ::Dynamic > _g3 = child->childNodes;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(81)
						while(((_g2 < _g3->length))){
							HX_STACK_LINE(81)
							::GSSNode x = _g3->__get(_g2).StaticCast< ::GSSNode >();		HX_STACK_VAR(x,"x");
							HX_STACK_LINE(81)
							++(_g2);
							HX_STACK_LINE(81)
							x->setParent(hx::ObjectPtr<OBJ_>(this));
						}
					}
					HX_STACK_LINE(82)
					hx::AddEq(val,child->getValue(variables,mixins));
					HX_STACK_LINE(83)
					hx::AddEq(val,HX_CSTRING("\n"));
				}
				else{
					HX_STACK_LINE(85)
					if (((bool((child->type == HX_CSTRING("selector"))) || bool((child->type == HX_CSTRING("when_pseudo")))))){
						HX_STACK_LINE(85)
						this->toAppendAfter->push(child->getValue(variables,mixins));
					}
				}
			}
		}
		HX_STACK_LINE(89)
		hx::AddEq(val,HX_CSTRING("}\n"));
		HX_STACK_LINE(90)
		{
			HX_STACK_LINE(90)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->toAppendAfter;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(90)
			while(((_g < _g1->length))){
				HX_STACK_LINE(90)
				::String item = _g1->__get(_g);		HX_STACK_VAR(item,"item");
				HX_STACK_LINE(90)
				++(_g);
				HX_STACK_LINE(90)
				hx::AddEq(val,item);
			}
		}
		HX_STACK_LINE(91)
		return val;
	}
	else{
		HX_STACK_LINE(93)
		if (((this->type == HX_CSTRING("prop_assignment")))){
			HX_STACK_LINE(98)
			Array< ::String > vendorPrefixes = this->getPrefixes(this->name.substring((int)1,null()));		HX_STACK_VAR(vendorPrefixes,"vendorPrefixes");
			::String mode = HX_CSTRING("normal");		HX_STACK_VAR(mode,"mode");
			HX_STACK_LINE(100)
			if (((this->name.substring((int)0,(int)1) == HX_CSTRING("~")))){
				HX_STACK_LINE(100)
				mode = HX_CSTRING("prefixed");
			}
			HX_STACK_LINE(103)
			::String val = HX_CSTRING("");		HX_STACK_VAR(val,"val");
			::String value = HX_CSTRING("");		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(104)
			if (((this->value.substring((int)0,(int)1) == HX_CSTRING("@")))){
				HX_STACK_LINE(105)
				::String name = this->value.substring((int)1,this->value.length);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(106)
				if (((variables->get(name) != null()))){
					HX_STACK_LINE(106)
					hx::AddEq(value,::Std_obj::string(variables->get(name)));
				}
			}
			else{
				HX_STACK_LINE(108)
				hx::AddEq(value,this->value);
			}
			HX_STACK_LINE(112)
			::String spaces = this->getIndentation();		HX_STACK_VAR(spaces,"spaces");
			HX_STACK_LINE(113)
			if (((mode == HX_CSTRING("prefixed")))){
				HX_STACK_LINE(114)
				::String name = this->name.substring((int)1,this->name.length);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(115)
				hx::AddEq(val,(spaces + (((((HX_CSTRING("") + name) + HX_CSTRING(" : ")) + value) + HX_CSTRING(";\n")))));
				HX_STACK_LINE(116)
				{
					HX_STACK_LINE(116)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(116)
					while(((_g < vendorPrefixes->length))){
						HX_STACK_LINE(116)
						::String prefix = vendorPrefixes->__get(_g);		HX_STACK_VAR(prefix,"prefix");
						HX_STACK_LINE(116)
						++(_g);
						HX_STACK_LINE(117)
						hx::AddEq(val,(spaces + (((((((HX_CSTRING("-") + prefix) + HX_CSTRING("-")) + name) + HX_CSTRING(" : ")) + value) + HX_CSTRING(";\n")))));
					}
				}
			}
			else{
				HX_STACK_LINE(119)
				hx::AddEq(val,(spaces + (((((HX_CSTRING("") + this->name) + HX_CSTRING(" : ")) + value) + HX_CSTRING(";")))));
			}
			HX_STACK_LINE(122)
			return val;
		}
		else{
			HX_STACK_LINE(124)
			if (((this->type == HX_CSTRING("when_pseudo")))){
				HX_STACK_LINE(124)
				if ((this->hasParent)){
					HX_STACK_LINE(126)
					::String rawSelector = ((getFullSelectorString(hx::ObjectPtr<OBJ_>(this)).Cast< ::String >() + HX_CSTRING(":")) + this->name);		HX_STACK_VAR(rawSelector,"rawSelector");
					HX_STACK_LINE(127)
					::String selector = ::StringTools_obj::replace(rawSelector,HX_CSTRING(" null"),HX_CSTRING(""));		HX_STACK_VAR(selector,"selector");
					HX_STACK_LINE(128)
					selector = ::StringTools_obj::replace(selector,HX_CSTRING(" :"),HX_CSTRING(":"));
					HX_STACK_LINE(129)
					::String val = ((HX_CSTRING("") + selector) + HX_CSTRING(" {\n"));		HX_STACK_VAR(val,"val");
					HX_STACK_LINE(130)
					{
						HX_STACK_LINE(130)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::Dynamic > _g1 = this->childNodes;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(130)
						while(((_g < _g1->length))){
							HX_STACK_LINE(130)
							::GSSNode child = _g1->__get(_g).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
							HX_STACK_LINE(130)
							++(_g);
							HX_STACK_LINE(131)
							if (((child->type == HX_CSTRING("selector")))){
								HX_STACK_LINE(132)
								::String stuff = ::StringTools_obj::replace(child->getValue(variables,mixins),rawSelector,selector);		HX_STACK_VAR(stuff,"stuff");
								HX_STACK_LINE(133)
								stuff = ::StringTools_obj::replace(stuff,HX_CSTRING(" null"),HX_CSTRING(""));
								HX_STACK_LINE(134)
								stuff = ::StringTools_obj::replace(stuff,this->parent->value,((this->parent->value + HX_CSTRING(":")) + this->name));
								HX_STACK_LINE(135)
								this->toAppendAfter->push(stuff);
							}
							else{
								HX_STACK_LINE(137)
								hx::AddEq(val,child->getValue(variables,mixins));
								HX_STACK_LINE(138)
								hx::AddEq(val,HX_CSTRING("\n"));
							}
						}
					}
					HX_STACK_LINE(141)
					hx::AddEq(val,HX_CSTRING("}\n"));
					HX_STACK_LINE(142)
					{
						HX_STACK_LINE(142)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::String > _g1 = this->toAppendAfter;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(142)
						while(((_g < _g1->length))){
							HX_STACK_LINE(142)
							::String item = _g1->__get(_g);		HX_STACK_VAR(item,"item");
							HX_STACK_LINE(142)
							++(_g);
							HX_STACK_LINE(143)
							hx::AddEq(val,item);
						}
					}
					HX_STACK_LINE(145)
					return val;
				}
				else{
					HX_STACK_LINE(146)
					return HX_CSTRING("");
				}
			}
			else{
				HX_STACK_LINE(150)
				if (((this->type == HX_CSTRING("var_assignment")))){
					HX_STACK_LINE(151)
					variables->set(this->name,this->value);
					HX_STACK_LINE(152)
					return HX_CSTRING("");
				}
				else{
					HX_STACK_LINE(154)
					if (((this->type == HX_CSTRING("mixin_declaration")))){
						HX_STACK_LINE(155)
						mixins->set(this->name,hx::ObjectPtr<OBJ_>(this));
						HX_STACK_LINE(156)
						return HX_CSTRING("");
					}
					else{
						HX_STACK_LINE(158)
						if (((this->type == HX_CSTRING("mixin_reference")))){
							HX_STACK_LINE(158)
							if (((mixins->get(this->name) != null()))){
								HX_STACK_LINE(160)
								::GSSNode mixin = mixins->get(this->name);		HX_STACK_VAR(mixin,"mixin");
								HX_STACK_LINE(161)
								::String val = HX_CSTRING("");		HX_STACK_VAR(val,"val");
								HX_STACK_LINE(162)
								{
									HX_STACK_LINE(162)
									int _g = (int)0;		HX_STACK_VAR(_g,"_g");
									Array< ::Dynamic > _g1 = mixin->childNodes;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(162)
									while(((_g < _g1->length))){
										HX_STACK_LINE(162)
										::GSSNode child = _g1->__get(_g).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
										HX_STACK_LINE(162)
										++(_g);
										HX_STACK_LINE(163)
										if (((bool((child->type == HX_CSTRING("selector"))) || bool((child->type == HX_CSTRING("when_pseudo")))))){
											HX_STACK_LINE(164)
											::String selector = getFullSelectorString(this->parent).Cast< ::String >();		HX_STACK_VAR(selector,"selector");
											HX_STACK_LINE(165)
											::haxe::Log_obj::trace(HX_CSTRING("THIS IS THE SELECTOR:"),hx::SourceInfo(HX_CSTRING("GSSNode.hx"),165,HX_CSTRING("GSSNode"),HX_CSTRING("getValue")));
											HX_STACK_LINE(166)
											::haxe::Log_obj::trace(selector,hx::SourceInfo(HX_CSTRING("GSSNode.hx"),166,HX_CSTRING("GSSNode"),HX_CSTRING("getValue")));
											HX_STACK_LINE(167)
											::String thatVal = child->getValue(variables,mixins);		HX_STACK_VAR(thatVal,"thatVal");
											HX_STACK_LINE(168)
											::haxe::Log_obj::trace(thatVal,hx::SourceInfo(HX_CSTRING("GSSNode.hx"),168,HX_CSTRING("GSSNode"),HX_CSTRING("getValue")));
											HX_STACK_LINE(169)
											this->parent->toAppendAfter->push((selector + thatVal));
										}
										else{
											HX_STACK_LINE(171)
											hx::AddEq(val,child->getValue(variables,mixins));
											HX_STACK_LINE(172)
											hx::AddEq(val,HX_CSTRING("\n"));
										}
									}
								}
								HX_STACK_LINE(175)
								return val;
							}
							else{
								HX_STACK_LINE(176)
								hx::Throw (((HX_CSTRING("ReferenceError:  ") + this->name) + HX_CSTRING(" is either not defined, or not a valid mixin.")));
							}
						}
						else{
							HX_STACK_LINE(181)
							if (((this->type == HX_CSTRING("comment")))){
								HX_STACK_LINE(181)
								return ((HX_CSTRING("/*\n") + this->value) + HX_CSTRING("\n*/"));
							}
							else{
								HX_STACK_LINE(185)
								if (((this->type == HX_CSTRING("string")))){
									HX_STACK_LINE(185)
									return ((HX_CSTRING("\"") + this->value) + HX_CSTRING("\""));
								}
								else{
									HX_STACK_LINE(188)
									return HX_CSTRING("");
								}
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(76)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GSSNode_obj,getValue,return )

Array< ::String > GSSNode_obj::getPrefixes( ::String name){
	HX_STACK_PUSH("GSSNode::getPrefixes","GSSNode.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	struct _Function_1_1{
		inline static ::haxe::ds::StringMap Block( ){
			HX_STACK_PUSH("*::closure","GSSNode.hx",46);
			{
				HX_STACK_LINE(46)
				::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("align-content"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("align-items"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("align-self"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("animation"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("background-size"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("border-image"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")).Add(HX_CSTRING("o")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("border-radius"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				_g->set(HX_CSTRING("linear-gradient"),Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")));
				HX_STACK_LINE(46)
				return _g;
			}
			return null();
		}
	};
	HX_STACK_LINE(46)
	::haxe::ds::StringMap prefixer = _Function_1_1::Block();		HX_STACK_VAR(prefixer,"prefixer");
	HX_STACK_LINE(56)
	if (((prefixer->get(name) != null()))){
		HX_STACK_LINE(56)
		return prefixer->get(name);
	}
	else{
		HX_STACK_LINE(58)
		return Array_obj< ::String >::__new().Add(HX_CSTRING("webkit")).Add(HX_CSTRING("moz")).Add(HX_CSTRING("o")).Add(HX_CSTRING("ms"));
	}
	HX_STACK_LINE(56)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSSNode_obj,getPrefixes,return )

Void GSSNode_obj::setValue( ::String val){
{
		HX_STACK_PUSH("GSSNode::setValue","GSSNode.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_ARG(val,"val");
		HX_STACK_LINE(41)
		this->value = val;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSSNode_obj,setValue,(void))

Void GSSNode_obj::setName( ::String name){
{
		HX_STACK_PUSH("GSSNode::setName","GSSNode.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(38)
		this->name = name;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSSNode_obj,setName,(void))

Void GSSNode_obj::setParent( ::GSSNode parent){
{
		HX_STACK_PUSH("GSSNode::setParent","GSSNode.hx",33);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parent,"parent");
		HX_STACK_LINE(34)
		this->parent = parent;
		HX_STACK_LINE(35)
		if ((!(this->hasParent))){
			HX_STACK_LINE(35)
			this->hasParent = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSSNode_obj,setParent,(void))

Void GSSNode_obj::appendChild( ::GSSNode child){
{
		HX_STACK_PUSH("GSSNode::appendChild","GSSNode.hx",28);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(29)
		this->childNodes->push(child);
		HX_STACK_LINE(30)
		child->setParent(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSSNode_obj,appendChild,(void))

::String GSSNode_obj::getIndentation( ){
	HX_STACK_PUSH("GSSNode::getIndentation","GSSNode.hx",18);
	HX_STACK_THIS(this);
	HX_STACK_LINE(19)
	int indentations = (int)0;		HX_STACK_VAR(indentations,"indentations");
	HX_STACK_LINE(21)
	if ((this->hasParent)){
		HX_STACK_LINE(21)
		hx::AddEq(indentations,this->indents);
	}
	HX_STACK_LINE(23)
	::String spaces = HX_CSTRING("");		HX_STACK_VAR(spaces,"spaces");
	HX_STACK_LINE(24)
	{
		HX_STACK_LINE(24)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(24)
		while(((_g < indentations))){
			HX_STACK_LINE(24)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(24)
			hx::AddEq(spaces,HX_CSTRING(" "));
		}
	}
	HX_STACK_LINE(25)
	return spaces;
}


HX_DEFINE_DYNAMIC_FUNC0(GSSNode_obj,getIndentation,return )


GSSNode_obj::GSSNode_obj()
{
}

void GSSNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GSSNode);
	HX_MARK_MEMBER_NAME(toAppendAfter,"toAppendAfter");
	HX_MARK_MEMBER_NAME(childNodes,"childNodes");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(hasParent,"hasParent");
	HX_MARK_MEMBER_NAME(indents,"indents");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_END_CLASS();
}

void GSSNode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(toAppendAfter,"toAppendAfter");
	HX_VISIT_MEMBER_NAME(childNodes,"childNodes");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(hasParent,"hasParent");
	HX_VISIT_MEMBER_NAME(indents,"indents");
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(type,"type");
}

Dynamic GSSNode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setName") ) { return setName_dyn(); }
		if (HX_FIELD_EQ(inName,"indents") ) { return indents; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getValue") ) { return getValue_dyn(); }
		if (HX_FIELD_EQ(inName,"setValue") ) { return setValue_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setParent") ) { return setParent_dyn(); }
		if (HX_FIELD_EQ(inName,"hasParent") ) { return hasParent; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"childNodes") ) { return childNodes; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getChildren") ) { return getChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"getPrefixes") ) { return getPrefixes_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"toAppendAfter") ) { return toAppendAfter; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getIndentation") ) { return getIndentation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GSSNode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::GSSNode >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indents") ) { indents=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasParent") ) { hasParent=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"childNodes") ) { childNodes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"toAppendAfter") ) { toAppendAfter=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GSSNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("toAppendAfter"));
	outFields->push(HX_CSTRING("childNodes"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("hasParent"));
	outFields->push(HX_CSTRING("indents"));
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("type"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getChildren"),
	HX_CSTRING("getValue"),
	HX_CSTRING("getPrefixes"),
	HX_CSTRING("setValue"),
	HX_CSTRING("setName"),
	HX_CSTRING("setParent"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("getIndentation"),
	HX_CSTRING("toAppendAfter"),
	HX_CSTRING("childNodes"),
	HX_CSTRING("parent"),
	HX_CSTRING("hasParent"),
	HX_CSTRING("indents"),
	HX_CSTRING("value"),
	HX_CSTRING("name"),
	HX_CSTRING("type"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GSSNode_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GSSNode_obj::__mClass,"__mClass");
};

Class GSSNode_obj::__mClass;

void GSSNode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GSSNode"), hx::TCanCast< GSSNode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GSSNode_obj::__boot()
{
}

