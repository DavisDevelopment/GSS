#include <hxcpp.h>

#ifndef INCLUDED_Builtins
#include <Builtins.h>
#endif
#ifndef INCLUDED_Console
#include <Console.h>
#endif
#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_GSS
#include <GSS.h>
#endif
#ifndef INCLUDED_GSSFunction
#include <GSSFunction.h>
#endif
#ifndef INCLUDED_GSSHelper
#include <GSSHelper.h>
#endif
#ifndef INCLUDED_GSSNode
#include <GSSNode.h>
#endif
#ifndef INCLUDED_Helpers
#include <Helpers.h>
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
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

Void GSS_obj::__construct(Dynamic getFile,::String dir,Dynamic __o_doExport)
{
HX_STACK_PUSH("GSS::new","GSS.hx",17);
Dynamic doExport = __o_doExport.Default(false);
{
	HX_STACK_LINE(18)
	if (((getFile == null()))){

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
		::String run(::String path){
			HX_STACK_PUSH("*::_Function_2_1","GSS.hx",18);
			HX_STACK_ARG(path,"path");
			{
				HX_STACK_LINE(18)
				return HX_CSTRING("");
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(18)
		getFile =  Dynamic(new _Function_2_1());
	}
	HX_STACK_LINE(21)
	this->doExport = doExport;
	HX_STACK_LINE(22)
	this->variables = ::Mapper_obj::__new(null(),null());
	HX_STACK_LINE(23)
	this->mixins = ::Mapper_obj::__new(null(),null());
	HX_STACK_LINE(24)
	this->functions = ::Mapper_obj::__new(null(),null());
	HX_STACK_LINE(25)
	this->helpers = ::Mapper_obj::__new(null(),null());
	HX_STACK_LINE(26)
	this->getFile = getFile;
	HX_STACK_LINE(27)
	this->__dir__ = dir;
}
;
	return null();
}

GSS_obj::~GSS_obj() { }

Dynamic GSS_obj::__CreateEmpty() { return  new GSS_obj; }
hx::ObjectPtr< GSS_obj > GSS_obj::__new(Dynamic getFile,::String dir,Dynamic __o_doExport)
{  hx::ObjectPtr< GSS_obj > result = new GSS_obj();
	result->__construct(getFile,dir,__o_doExport);
	return result;}

Dynamic GSS_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GSS_obj > result = new GSS_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void GSS_obj::gss_import( ::String path){
{
		HX_STACK_PUSH("GSS::gss_import","GSS.hx",692);
		HX_STACK_THIS(this);
		HX_STACK_ARG(path,"path");
		HX_STACK_LINE(693)
		::String input = (this->getFile(path) + HX_CSTRING(""));		HX_STACK_VAR(input,"input");
		HX_STACK_LINE(694)
		::Console_obj::log(HX_CSTRING("Got Import"));
		HX_STACK_LINE(695)
		::GSS gss = ::GSS_obj::__new(this->getFile_dyn(),null(),true);		HX_STACK_VAR(gss,"gss");
		HX_STACK_LINE(696)
		::Helpers_obj::bind(gss);
		HX_STACK_LINE(697)
		::Builtins_obj::bind(gss);
		HX_STACK_LINE(698)
		Array< ::Dynamic > tokens = gss->lex(input);		HX_STACK_VAR(tokens,"tokens");
		HX_STACK_LINE(699)
		::Console_obj::log(HX_CSTRING("Tokenized Import"));
		HX_STACK_LINE(700)
		Array< ::Dynamic > ast = gss->parse(tokens);		HX_STACK_VAR(ast,"ast");
		HX_STACK_LINE(701)
		::Console_obj::log(HX_CSTRING("Parsed Import"));
		HX_STACK_LINE(702)
		gss->interpret(ast);
		HX_STACK_LINE(703)
		::Console_obj::log(HX_CSTRING("Interpreted Import"));
		HX_STACK_LINE(704)
		{
			HX_STACK_LINE(704)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = gss->variables->keys;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(704)
			while(((_g < _g1->length))){
				HX_STACK_LINE(704)
				::String key = _g1->__get(_g);		HX_STACK_VAR(key,"key");
				HX_STACK_LINE(704)
				++(_g);
				HX_STACK_LINE(705)
				this->variables->set(key,gss->variables->get(key));
			}
		}
		HX_STACK_LINE(707)
		{
			HX_STACK_LINE(707)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = gss->mixins->keys;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(707)
			while(((_g < _g1->length))){
				HX_STACK_LINE(707)
				::String key = _g1->__get(_g);		HX_STACK_VAR(key,"key");
				HX_STACK_LINE(707)
				++(_g);
				HX_STACK_LINE(708)
				this->mixins->set(key,gss->mixins->get(key));
			}
		}
		HX_STACK_LINE(710)
		{
			HX_STACK_LINE(710)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = gss->functions->keys;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(710)
			while(((_g < _g1->length))){
				HX_STACK_LINE(710)
				::String key = _g1->__get(_g);		HX_STACK_VAR(key,"key");
				HX_STACK_LINE(710)
				++(_g);
				HX_STACK_LINE(711)
				this->functions->set(key,gss->functions->get(key));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,gss_import,(void))

Void GSS_obj::interpret( Array< ::Dynamic > ast){
{
		HX_STACK_PUSH("GSS::interpret","GSS.hx",687);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ast,"ast");
		HX_STACK_LINE(688)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(688)
		while(((_g < ast->length))){
			HX_STACK_LINE(688)
			::GSSNode node = ast->__get(_g).StaticCast< ::GSSNode >();		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(688)
			++(_g);
			HX_STACK_LINE(689)
			node->getValue(this->variables,this->mixins);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,interpret,(void))

::String GSS_obj::compile( Array< ::Dynamic > ast){
	HX_STACK_PUSH("GSS::compile","GSS.hx",678);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ast,"ast");
	HX_STACK_LINE(679)
	::String css = HX_CSTRING("/*\nGenerated from GSS code using the GSS -> CSS Compiler, written by Ryan Davis.\n*/\n\n");		HX_STACK_VAR(css,"css");
	HX_STACK_LINE(680)
	{
		HX_STACK_LINE(680)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(680)
		while(((_g < ast->length))){
			HX_STACK_LINE(680)
			::GSSNode node = ast->__get(_g).StaticCast< ::GSSNode >();		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(680)
			++(_g);
			HX_STACK_LINE(681)
			if (((node->type == HX_CSTRING("mixin_declaration")))){
				HX_STACK_LINE(681)
				node->getValue(this->variables,this->mixins);
			}
			HX_STACK_LINE(682)
			hx::AddEq(css,node->getValue(this->variables,this->mixins));
		}
	}
	HX_STACK_LINE(685)
	return css;
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,compile,return )

Array< ::Dynamic > GSS_obj::parse( Array< ::Dynamic > tokens){
	HX_STACK_PUSH("GSS::parse","GSS.hx",183);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tokens,"tokens");
	HX_STACK_LINE(183)
	Array< ::Dynamic > tokens1 = Array_obj< ::Dynamic >::__new().Add(tokens);		HX_STACK_VAR(tokens1,"tokens1");
	HX_STACK_LINE(183)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(184)
	Array< ::Dynamic > nodeTree = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(nodeTree,"nodeTree");
	HX_STACK_LINE(185)
	Array< ::Dynamic > mixinList = Array_obj< ::Dynamic >::__new().Add(this->mixins);		HX_STACK_VAR(mixinList,"mixinList");
	HX_STACK_LINE(186)
	Array< int > i = Array_obj< int >::__new().Add((int)0);		HX_STACK_VAR(i,"i");
	Array< ::Dynamic > token = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(token,"token");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,nodeTree)
	Void run(::GSSNode node){
		HX_STACK_PUSH("*::_Function_1_1","GSS.hx",187);
		HX_STACK_ARG(node,"node");
		{
			HX_STACK_LINE(187)
			nodeTree->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(node);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(187)
	Dynamic addNode =  Dynamic(new _Function_1_1(nodeTree));		HX_STACK_VAR(addNode,"addNode");

	HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,token,Array< ::Dynamic >,tokens1,Array< int >,i)
	Void run(hx::Null< int >  __o_dis){
		int dis = __o_dis.Default(1);
		{
			HX_STACK_PUSH("*::_Function_1_2","GSS.hx",190);
			HX_STACK_ARG(dis,"dis");
			{
				HX_STACK_LINE(191)
				hx::AddEq(i[(int)0],dis);
				HX_STACK_LINE(192)
				token[(int)0] = tokens1->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(i->__get((int)0)).StaticCast< Array< ::String > >();
			}
			return null();
		}
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(190)
	Dynamic advance = Dynamic( Array_obj<Dynamic>::__new().Add( Dynamic(new _Function_1_2(token,tokens1,i))));		HX_STACK_VAR(advance,"advance");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_3,Array< ::Dynamic >,tokens1,Array< int >,i)
	Array< ::String > run(hx::Null< int >  __o_dis){
		int dis = __o_dis.Default(1);
		{
			HX_STACK_PUSH("*::_Function_1_3","GSS.hx",194);
			HX_STACK_ARG(dis,"dis");
			{
				HX_STACK_LINE(194)
				return tokens1->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get((i->__get((int)0) + dis)).StaticCast< Array< ::String > >();
			}
			return null();
		}
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(194)
	Dynamic next = Dynamic( Array_obj<Dynamic>::__new().Add( Dynamic(new _Function_1_3(tokens1,i))));		HX_STACK_VAR(next,"next");
	struct _Function_1_4{
		inline static Dynamic Block( Array< ::Dynamic > &_g,Array< ::Dynamic > &nodeTree){
			HX_STACK_PUSH("*::closure","GSS.hx",198);
			{
				HX_STACK_LINE(198)
				Dynamic parseStyleGroup = Dynamic( Array_obj<Dynamic>::__new().Add(null()));		HX_STACK_VAR(parseStyleGroup,"parseStyleGroup");

				HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_2_1,Dynamic,parseStyleGroup,Array< ::Dynamic >,_g,Array< ::Dynamic >,nodeTree)
				Array< ::Dynamic > run(Array< ::Dynamic > group){
					HX_STACK_PUSH("*::_Function_2_1","GSS.hx",198);
					HX_STACK_ARG(group,"group");
					{
						HX_STACK_LINE(199)
						Array< ::Dynamic > styleGroup = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(styleGroup,"styleGroup");
						HX_STACK_LINE(200)
						int i1 = (int)0;		HX_STACK_VAR(i1,"i1");
						Array< ::String > token1 = group->__get(i1).StaticCast< Array< ::String > >();		HX_STACK_VAR(token1,"token1");
						HX_STACK_LINE(201)
						::Console_obj::log(group);
						HX_STACK_LINE(203)
						while(((i1 < group->length))){
							HX_STACK_LINE(204)
							token1 = group->__get(i1).StaticCast< Array< ::String > >();
							HX_STACK_LINE(208)
							if (((bool((group->__get(i1).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("identifier"))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING(";")))))){
								HX_STACK_LINE(209)
								::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("mixin_reference"));		HX_STACK_VAR(node,"node");
								HX_STACK_LINE(210)
								node->setName(token1->__get((int)1));
								HX_STACK_LINE(211)
								styleGroup->push(node);
								HX_STACK_LINE(213)
								hx::AddEq(i1,(int)2);
							}
							else{
								HX_STACK_LINE(216)
								if (((bool((bool((bool((token1->__get((int)0) == HX_CSTRING("identifier"))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("{"))))) || bool((bool((token1->__get((int)0) == HX_CSTRING("identifier"))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("identifier"))))))) || bool((bool((bool((token1->__get((int)0) == HX_CSTRING("identifier"))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING(":"))))) && bool((group->__get((i1 + (int)2)).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("pseudo_class")))))))){
									HX_STACK_LINE(217)
									int dis = (int)1;		HX_STACK_VAR(dis,"dis");
									::String selector = token1->__get((int)1);		HX_STACK_VAR(selector,"selector");
									HX_STACK_LINE(218)
									while(((bool((bool((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("identifier"))) || bool((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING(":"))))) || bool((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("pseudo_class")))))){
										HX_STACK_LINE(219)
										if ((!(((bool((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING(":"))) || bool((group->__get(((i1 + dis) - (int)1)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING(":")))))))){
											HX_STACK_LINE(219)
											hx::AddEq(selector,HX_CSTRING(" "));
										}
										HX_STACK_LINE(220)
										hx::AddEq(selector,group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1));
										HX_STACK_LINE(221)
										(dis)++;
									}
									HX_STACK_LINE(223)
									hx::AddEq(i1,dis);
									HX_STACK_LINE(224)
									::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("selector"));		HX_STACK_VAR(node,"node");
									HX_STACK_LINE(225)
									node->setValue(selector);
									HX_STACK_LINE(226)
									if (((group->__get(i1).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("{")))){
										HX_STACK_LINE(227)
										int d = (int)1;		HX_STACK_VAR(d,"d");
										Array< ::Dynamic > list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(list,"list");
										HX_STACK_LINE(228)
										int brackets = (int)1;		HX_STACK_VAR(brackets,"brackets");
										HX_STACK_LINE(229)
										while(((brackets > (int)0))){
											HX_STACK_LINE(230)
											if (((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("{")))){
												HX_STACK_LINE(230)
												(brackets)++;
											}
											else{
												HX_STACK_LINE(231)
												if (((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("}")))){
													HX_STACK_LINE(231)
													(brackets)--;
												}
											}
											HX_STACK_LINE(233)
											if ((!(((bool((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("}"))) && bool((brackets == (int)0))))))){
												HX_STACK_LINE(233)
												list->push(group->__get((i1 + d)).StaticCast< Array< ::String > >());
											}
											HX_STACK_LINE(236)
											(d)++;
										}
										HX_STACK_LINE(238)
										Array< ::Dynamic > children = parseStyleGroup->__GetItem((int)0)(list).Cast< Array< ::Dynamic > >();		HX_STACK_VAR(children,"children");
										HX_STACK_LINE(239)
										{
											HX_STACK_LINE(239)
											int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
											HX_STACK_LINE(239)
											while(((_g1 < children->length))){
												HX_STACK_LINE(239)
												::GSSNode child = children->__get(_g1).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
												HX_STACK_LINE(239)
												++(_g1);
												HX_STACK_LINE(239)
												node->appendChild(child);
											}
										}
										HX_STACK_LINE(240)
										hx::AddEq(i1,d);
										HX_STACK_LINE(241)
										styleGroup->push(node);
									}
									else{
										HX_STACK_LINE(243)
										::Console_obj::log(group->__get(i1).StaticCast< Array< ::String > >());
										HX_STACK_LINE(244)
										hx::Throw (HX_CSTRING("SyntaxError:  Unexpected Selector String."));
									}
								}
								else{
									HX_STACK_LINE(249)
									if (((bool((bool((token1->__get((int)0) == HX_CSTRING("keyword"))) && bool((token1->__get((int)1) == HX_CSTRING("when"))))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("keyword")))))){
										HX_STACK_LINE(250)
										::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("when_pseudo"));		HX_STACK_VAR(node,"node");
										struct _Function_7_1{
											inline static ::haxe::ds::StringMap Block( ){
												HX_STACK_PUSH("*::closure","GSS.hx",251);
												{
													HX_STACK_LINE(251)
													::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
													HX_STACK_LINE(251)
													_g1->set(HX_CSTRING("active"),HX_CSTRING("active"));
													HX_STACK_LINE(251)
													_g1->set(HX_CSTRING("hovered"),HX_CSTRING("hover"));
													HX_STACK_LINE(251)
													return _g1;
												}
												return null();
											}
										};
										HX_STACK_LINE(251)
										::haxe::ds::StringMap pseudoNames = _Function_7_1::Block();		HX_STACK_VAR(pseudoNames,"pseudoNames");
										HX_STACK_LINE(255)
										node->setName(pseudoNames->get(group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)1)));
										HX_STACK_LINE(256)
										hx::AddEq(i1,(int)2);
										HX_STACK_LINE(258)
										int d = (int)1;		HX_STACK_VAR(d,"d");
										Array< ::Dynamic > list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(list,"list");
										int brackets = (int)1;		HX_STACK_VAR(brackets,"brackets");
										HX_STACK_LINE(260)
										while(((brackets > (int)0))){
											HX_STACK_LINE(261)
											if (((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("{")))){
												HX_STACK_LINE(261)
												(brackets)++;
											}
											else{
												HX_STACK_LINE(262)
												if (((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("}")))){
													HX_STACK_LINE(262)
													(brackets)--;
												}
											}
											HX_STACK_LINE(263)
											if ((!(((bool((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("}"))) && bool((brackets == (int)0))))))){
												HX_STACK_LINE(263)
												list->push(group->__get((i1 + d)).StaticCast< Array< ::String > >());
											}
											HX_STACK_LINE(266)
											(d)++;
										}
										HX_STACK_LINE(268)
										hx::AddEq(i1,d);
										HX_STACK_LINE(270)
										Array< ::Dynamic > children = parseStyleGroup->__GetItem((int)0)(list).Cast< Array< ::Dynamic > >();		HX_STACK_VAR(children,"children");
										HX_STACK_LINE(271)
										{
											HX_STACK_LINE(271)
											int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
											HX_STACK_LINE(271)
											while(((_g1 < children->length))){
												HX_STACK_LINE(271)
												::GSSNode child = children->__get(_g1).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
												HX_STACK_LINE(271)
												++(_g1);
												HX_STACK_LINE(271)
												node->appendChild(child);
											}
										}
										HX_STACK_LINE(272)
										styleGroup->push(node);
									}
									else{
										HX_STACK_LINE(275)
										if (((bool((bool((token1->__get((int)0) == HX_CSTRING("identifier"))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING(":"))))) && bool((group->__get((i1 + (int)2)).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("identifier")))))){
											HX_STACK_LINE(276)
											::String mode = HX_CSTRING("prop_assignment");		HX_STACK_VAR(mode,"mode");
											HX_STACK_LINE(277)
											::String valType = HX_CSTRING("normal");		HX_STACK_VAR(valType,"valType");
											HX_STACK_LINE(278)
											if (((group->__get((i1 + (int)3)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("(")))){
												HX_STACK_LINE(278)
												valType = HX_CSTRING("helper_call");
											}
											HX_STACK_LINE(279)
											::String val = HX_CSTRING("");		HX_STACK_VAR(val,"val");
											int d = (int)0;		HX_STACK_VAR(d,"d");
											HX_STACK_LINE(282)
											if (((valType == HX_CSTRING("normal")))){
												HX_STACK_LINE(283)
												d = (int)3;
												HX_STACK_LINE(284)
												val = group->__get((i1 + (int)2)).StaticCast< Array< ::String > >()->__get((int)1);
												HX_STACK_LINE(285)
												while(((group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1) != HX_CSTRING(";")))){
													HX_STACK_LINE(286)
													hx::AddEq(val,(HX_CSTRING(" ") + group->__get((i1 + d)).StaticCast< Array< ::String > >()->__get((int)1)));
													HX_STACK_LINE(287)
													(d)++;
												}
											}
											else{
												HX_STACK_LINE(291)
												int dis = (int)4;		HX_STACK_VAR(dis,"dis");
												Array< ::String > args = Array_obj< ::String >::__new();		HX_STACK_VAR(args,"args");
												::String ref = group->__get((i1 + (int)2)).StaticCast< Array< ::String > >()->__get((int)1);		HX_STACK_VAR(ref,"ref");
												HX_STACK_LINE(292)
												while(((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1) != HX_CSTRING(")")))){
													HX_STACK_LINE(293)
													if (((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1) != HX_CSTRING(",")))){
														HX_STACK_LINE(293)
														args->push(::StringTools_obj::ltrim(::StringTools_obj::rtrim(group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1))));
													}
													HX_STACK_LINE(296)
													(dis)++;
												}
												HX_STACK_LINE(298)
												hx::AddEq(i1,(dis + (int)1));
												HX_STACK_LINE(300)
												if (((_g->__get((int)0).StaticCast< ::GSS >()->helpers->get(ref) != null()))){
													HX_STACK_LINE(301)
													::GSSHelper func = _g->__get((int)0).StaticCast< ::GSS >()->helpers->get(ref);		HX_STACK_VAR(func,"func");
													HX_STACK_LINE(303)
													val = func->__call__(args);
												}
												else{
													HX_STACK_LINE(305)
													val = ((((HX_CSTRING("") + ref) + HX_CSTRING("(")) + args->join(HX_CSTRING(","))) + HX_CSTRING(")"));
												}
											}
											HX_STACK_LINE(310)
											::GSSNode node;		HX_STACK_VAR(node,"node");
											HX_STACK_LINE(312)
											node = ::GSSNode_obj::__new(HX_CSTRING("prop_assignment"));
											HX_STACK_LINE(313)
											node->setName(token1->__get((int)1));
											HX_STACK_LINE(314)
											node->setValue(val);
											HX_STACK_LINE(332)
											styleGroup->push(node);
											HX_STACK_LINE(334)
											hx::AddEq(i1,(d + (int)1));
										}
										else{
											HX_STACK_LINE(337)
											if (((bool((group->__get(i1).StaticCast< Array< ::String > >()->__get((int)0) == HX_CSTRING("identifier"))) && bool((group->__get((i1 + (int)1)).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("(")))))){
												HX_STACK_LINE(338)
												int dis = (int)2;		HX_STACK_VAR(dis,"dis");
												Array< ::String > args = Array_obj< ::String >::__new();		HX_STACK_VAR(args,"args");
												HX_STACK_LINE(339)
												::String ref = group->__get(i1).StaticCast< Array< ::String > >()->__get((int)1);		HX_STACK_VAR(ref,"ref");
												HX_STACK_LINE(340)
												while(((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1) != HX_CSTRING(")")))){
													HX_STACK_LINE(341)
													if (((group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1) != HX_CSTRING(",")))){
														HX_STACK_LINE(341)
														args->push(::StringTools_obj::ltrim(::StringTools_obj::rtrim(group->__get((i1 + dis)).StaticCast< Array< ::String > >()->__get((int)1))));
													}
													HX_STACK_LINE(344)
													(dis)++;
												}
												HX_STACK_LINE(346)
												hx::AddEq(i1,(dis + (int)2));
												HX_STACK_LINE(347)
												if (((_g->__get((int)0).StaticCast< ::GSS >()->functions->get(ref) != null()))){
													HX_STACK_LINE(348)
													Array< ::Dynamic > mixedIn = _g->__get((int)0).StaticCast< ::GSS >()->functions->get(ref)->__Field(HX_CSTRING("__call__"),true)(args);		HX_STACK_VAR(mixedIn,"mixedIn");
													HX_STACK_LINE(349)
													{
														HX_STACK_LINE(349)
														int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
														HX_STACK_LINE(349)
														while(((_g1 < mixedIn->length))){
															HX_STACK_LINE(349)
															::GSSNode x = mixedIn->__get(_g1).StaticCast< ::GSSNode >();		HX_STACK_VAR(x,"x");
															HX_STACK_LINE(349)
															++(_g1);
															HX_STACK_LINE(349)
															styleGroup->push(x);
														}
													}
												}
												else{
													HX_STACK_LINE(351)
													::Console_obj::log(_g->__get((int)0).StaticCast< ::GSS >()->functions->keys);
													HX_STACK_LINE(352)
													hx::Throw (((HX_CSTRING("ReferenceError: ") + ref) + HX_CSTRING(" is either not defined, or not a valid function.")));
												}
											}
											else{
												HX_STACK_LINE(356)
												::Console_obj::log(nodeTree->__get((int)0).StaticCast< Array< ::Dynamic > >());
												HX_STACK_LINE(357)
												hx::Throw (((HX_CSTRING("Unexpected Token ") + ::Std_obj::string(token1)) + HX_CSTRING(".")));
											}
										}
									}
								}
							}
						}
						HX_STACK_LINE(361)
						return styleGroup;
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_STACK_LINE(198)
				hx::IndexRef((parseStyleGroup).mPtr,(int)0) =  Dynamic(new _Function_2_1(parseStyleGroup,_g,nodeTree));
				HX_STACK_LINE(198)
				return parseStyleGroup->__GetItem((int)0);
			}
			return null();
		}
	};
	HX_STACK_LINE(198)
	Dynamic parseStyleGroup = Dynamic( Array_obj<Dynamic>::__new().Add(_Function_1_4::Block(_g,nodeTree)));		HX_STACK_VAR(parseStyleGroup,"parseStyleGroup");

	HX_BEGIN_LOCAL_FUNC_S7(hx::LocalFunc,_Function_1_5,Dynamic,parseStyleGroup,Array< ::Dynamic >,_g,Dynamic,next,Array< ::Dynamic >,mixinList,Array< ::Dynamic >,token,Array< ::Dynamic >,nodeTree,Dynamic,advance)
	::GSSNode run(Array< ::String > tk,::GSSNode parent){
		HX_STACK_PUSH("*::_Function_1_5","GSS.hx",364);
		HX_STACK_ARG(tk,"tk");
		HX_STACK_ARG(parent,"parent");
		{
			HX_STACK_LINE(365)
			::String type = tk->__get((int)0);		HX_STACK_VAR(type,"type");
			::String value = tk->__get((int)1);		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(368)
			if (((bool((bool((type == HX_CSTRING("identifier"))) && bool((next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("{"))))) || bool((bool((type == HX_CSTRING("identifier"))) && bool((next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier")))))))){
				HX_STACK_LINE(369)
				int dis = (int)1;		HX_STACK_VAR(dis,"dis");
				::String selector = value;		HX_STACK_VAR(selector,"selector");
				HX_STACK_LINE(370)
				while(((bool((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier"))) || bool((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(":")))))){
					HX_STACK_LINE(371)
					if ((!(((bool((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(":"))) || bool((next->__GetItem((int)0)((dis - (int)1)).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(":")))))))){
						HX_STACK_LINE(371)
						hx::AddEq(selector,HX_CSTRING(" "));
					}
					HX_STACK_LINE(372)
					hx::AddEq(selector,next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1));
					HX_STACK_LINE(373)
					(dis)++;
				}
				HX_STACK_LINE(375)
				::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("selector"));		HX_STACK_VAR(node,"node");
				HX_STACK_LINE(376)
				node->setValue(selector);
				HX_STACK_LINE(377)
				advance->__GetItem((int)0)(dis).Cast< Void >();
				HX_STACK_LINE(378)
				if (((token->__get((int)0).StaticCast< Array< ::String > >()->__get((int)1) == HX_CSTRING("{")))){
					HX_STACK_LINE(379)
					int brackets = (int)1;		HX_STACK_VAR(brackets,"brackets");
					int dis1 = (int)1;		HX_STACK_VAR(dis1,"dis1");
					Array< ::Dynamic > list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(list,"list");
					HX_STACK_LINE(380)
					while(((brackets > (int)0))){
						HX_STACK_LINE(381)
						if (((next->__GetItem((int)0)(dis1).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("{")))){
							HX_STACK_LINE(381)
							(brackets)++;
						}
						else{
							HX_STACK_LINE(382)
							if (((next->__GetItem((int)0)(dis1).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}")))){
								HX_STACK_LINE(382)
								(brackets)--;
							}
						}
						HX_STACK_LINE(384)
						if ((!(((bool((next->__GetItem((int)0)(dis1).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}"))) && bool((brackets == (int)0))))))){
							HX_STACK_LINE(384)
							list->push(next->__GetItem((int)0)(dis1).Cast< Array< ::String > >());
						}
						HX_STACK_LINE(388)
						(dis1)++;
					}
					HX_STACK_LINE(390)
					advance->__GetItem((int)0)(dis1).Cast< Void >();
					HX_STACK_LINE(391)
					Array< ::Dynamic > children = parseStyleGroup->__GetItem((int)0)(list).Cast< Array< ::Dynamic > >();		HX_STACK_VAR(children,"children");
					HX_STACK_LINE(392)
					{
						HX_STACK_LINE(392)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(392)
						while(((_g1 < children->length))){
							HX_STACK_LINE(392)
							::GSSNode child = children->__get(_g1).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
							HX_STACK_LINE(392)
							++(_g1);
							HX_STACK_LINE(392)
							node->appendChild(child);
						}
					}
				}
				HX_STACK_LINE(394)
				return node;
			}
			else{
				HX_STACK_LINE(397)
				if (((bool((bool((type == HX_CSTRING("symbol"))) && bool((value == HX_CSTRING("{"))))) && bool((parent != null()))))){
					HX_STACK_LINE(398)
					int dis = (int)0;		HX_STACK_VAR(dis,"dis");
					Array< ::Dynamic > children = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(children,"children");
					HX_STACK_LINE(399)
					int openingBrackets = (int)1;		HX_STACK_VAR(openingBrackets,"openingBrackets");
					int closingBrackets = (int)0;		HX_STACK_VAR(closingBrackets,"closingBrackets");
					HX_STACK_LINE(400)
					while(((openingBrackets != closingBrackets))){
						HX_STACK_LINE(401)
						if (((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("{")))){
							HX_STACK_LINE(401)
							(openingBrackets)++;
						}
						else{
							HX_STACK_LINE(402)
							if (((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}")))){
								HX_STACK_LINE(402)
								(closingBrackets)++;
							}
						}
						HX_STACK_LINE(403)
						Array< ::String > n = next->__GetItem((int)0)(dis).Cast< Array< ::String > >();		HX_STACK_VAR(n,"n");
						HX_STACK_LINE(405)
						if (((bool((bool((n->__get((int)0) == HX_CSTRING("identifier"))) && bool((next->__GetItem((int)0)((dis + (int)1)).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(":"))))) && bool((next->__GetItem((int)0)((dis + (int)2)).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier")))))){
							HX_STACK_LINE(406)
							::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("prop_assignment"));		HX_STACK_VAR(node,"node");
							HX_STACK_LINE(407)
							node->setName(n->__get((int)1));
							HX_STACK_LINE(408)
							::String val = next->__GetItem((int)0)((dis + (int)2)).Cast< Array< ::String > >()->__GetItem((int)1);		HX_STACK_VAR(val,"val");
							int d = (int)3;		HX_STACK_VAR(d,"d");
							HX_STACK_LINE(409)
							while(((next->__GetItem((int)0)((dis + d)).Cast< Array< ::String > >()->__GetItem((int)1) != HX_CSTRING(";")))){
								HX_STACK_LINE(410)
								hx::AddEq(val,(HX_CSTRING(" ") + next->__GetItem((int)0)((dis + d)).Cast< Array< ::String > >()->__GetItem((int)1)));
								HX_STACK_LINE(411)
								(d)++;
							}
							HX_STACK_LINE(413)
							node->setValue(val);
							HX_STACK_LINE(414)
							parent->appendChild(node);
							HX_STACK_LINE(415)
							hx::AddEq(dis,(d + (int)1));
						}
						else{
							HX_STACK_LINE(418)
							if (((bool((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier"))) && bool((next->__GetItem((int)0)((dis + (int)1)).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(";")))))){
								HX_STACK_LINE(419)
								::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("mixin_reference"));		HX_STACK_VAR(node,"node");
								HX_STACK_LINE(420)
								node->setName(n->__get((int)1));
								HX_STACK_LINE(421)
								parent->appendChild(node);
								HX_STACK_LINE(422)
								hx::AddEq(dis,(int)2);
							}
							else{
								HX_STACK_LINE(424)
								(dis)++;
							}
						}
					}
					HX_STACK_LINE(428)
					advance->__GetItem((int)0)((dis + (int)1)).Cast< Void >();
					HX_STACK_LINE(429)
					return parent;
				}
				else{
					HX_STACK_LINE(432)
					if (((bool((bool((bool((type == HX_CSTRING("identifier"))) && bool((next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(":"))))) && bool((next->__GetItem((int)0)((int)2).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier"))))) && bool((next->__GetItem((int)0)((int)3).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING(";")))))){
						HX_STACK_LINE(432)
						if (((value.split(HX_CSTRING(""))->__get((int)0) == HX_CSTRING("@")))){
							HX_STACK_LINE(434)
							::String name = value.substring((int)1,value.length);		HX_STACK_VAR(name,"name");
							HX_STACK_LINE(435)
							::String val = next->__GetItem((int)0)((int)2).Cast< Array< ::String > >()->__GetItem((int)1);		HX_STACK_VAR(val,"val");
							HX_STACK_LINE(436)
							::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("var_assignment"));		HX_STACK_VAR(node,"node");
							HX_STACK_LINE(437)
							node->setName(name);
							HX_STACK_LINE(438)
							node->setValue(val);
							HX_STACK_LINE(439)
							advance->__GetItem((int)0)((int)4).Cast< Void >();
							HX_STACK_LINE(440)
							return node;
						}
						else{
							HX_STACK_LINE(441)
							hx::Throw (((((HX_CSTRING("Unexpected Property Assignment: [") + value) + HX_CSTRING(" : ")) + next->__GetItem((int)0)((int)2).Cast< Array< ::String > >()->__GetItem((int)1)) + HX_CSTRING("]")));
						}
					}
					else{
						HX_STACK_LINE(446)
						if (((bool((bool((type == HX_CSTRING("keyword"))) && bool((value == HX_CSTRING("mixin"))))) && bool((next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier")))))){
							HX_STACK_LINE(447)
							::String mixinType;		HX_STACK_VAR(mixinType,"mixinType");
							HX_STACK_LINE(448)
							if (((next->__GetItem((int)0)((int)2).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("(")))){
								HX_STACK_LINE(448)
								mixinType = HX_CSTRING("parametric");
							}
							else{
								HX_STACK_LINE(449)
								mixinType = HX_CSTRING("normal");
							}
							HX_STACK_LINE(454)
							if (((mixinType == HX_CSTRING("normal")))){
								HX_STACK_LINE(455)
								::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("mixin_declaration"));		HX_STACK_VAR(node,"node");
								HX_STACK_LINE(456)
								::String mode = HX_CSTRING("");		HX_STACK_VAR(mode,"mode");
								HX_STACK_LINE(457)
								::String name = next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)1);		HX_STACK_VAR(name,"name");
								HX_STACK_LINE(458)
								node->setName(name);
								HX_STACK_LINE(459)
								bool inherits = false;		HX_STACK_VAR(inherits,"inherits");
								Array< ::String > from = Array_obj< ::String >::__new();		HX_STACK_VAR(from,"from");
								HX_STACK_LINE(460)
								if (((bool((next->__GetItem((int)0)((int)2).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("keyword"))) && bool((next->__GetItem((int)0)((int)2).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("extends")))))){
									HX_STACK_LINE(461)
									inherits = true;
									HX_STACK_LINE(462)
									if (((next->__GetItem((int)0)((int)3).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("identifier")))){
										HX_STACK_LINE(463)
										mode = HX_CSTRING("single");
										HX_STACK_LINE(464)
										from->push(next->__GetItem((int)0)((int)3).Cast< Array< ::String > >()->__GetItem((int)1));
									}
									else{
										HX_STACK_LINE(466)
										if (((next->__GetItem((int)0)((int)3).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("(")))){
											HX_STACK_LINE(466)
											mode = HX_CSTRING("multiple");
										}
									}
								}
								HX_STACK_LINE(470)
								if (((mode == HX_CSTRING("multiple")))){
									HX_STACK_LINE(471)
									int dis = (int)4;		HX_STACK_VAR(dis,"dis");
									HX_STACK_LINE(472)
									while(((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) != HX_CSTRING(")")))){
										HX_STACK_LINE(473)
										::String ref = ::StringTools_obj::ltrim(::StringTools_obj::rtrim(next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1)));		HX_STACK_VAR(ref,"ref");
										HX_STACK_LINE(474)
										if (((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) != HX_CSTRING(",")))){
											HX_STACK_LINE(475)
											::Console_obj::log(ref);
											HX_STACK_LINE(476)
											from->push(ref);
										}
										HX_STACK_LINE(478)
										(dis)++;
									}
									HX_STACK_LINE(480)
									advance->__GetItem((int)0)(dis).Cast< Void >();
								}
								struct _Function_7_1{
									inline static int Block( ::String &mode){
										HX_STACK_PUSH("*::closure","GSS.hx",483);
										{
											HX_STACK_LINE(483)
											return (  (((mode == HX_CSTRING("multiple")))) ? int((int)2) : int((int)5) );
										}
										return null();
									}
								};
								HX_STACK_LINE(483)
								int brackets = (int)1;		HX_STACK_VAR(brackets,"brackets");
								Array< ::Dynamic > list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(list,"list");
								int dis = (  ((inherits)) ? int(_Function_7_1::Block(mode)) : int((int)3) );		HX_STACK_VAR(dis,"dis");
								HX_STACK_LINE(484)
								while(((brackets > (int)0))){
									HX_STACK_LINE(485)
									::Console_obj::log(next->__GetItem((int)0)(dis).Cast< Array< ::String > >());
									HX_STACK_LINE(486)
									if (((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("{")))){
										HX_STACK_LINE(486)
										(brackets)++;
									}
									else{
										HX_STACK_LINE(487)
										if (((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}")))){
											HX_STACK_LINE(487)
											(brackets)--;
										}
									}
									HX_STACK_LINE(488)
									if ((!(((bool((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}"))) && bool((brackets == (int)0))))))){
										HX_STACK_LINE(488)
										list->push(next->__GetItem((int)0)(dis).Cast< Array< ::String > >());
									}
									HX_STACK_LINE(491)
									(dis)++;
								}
								HX_STACK_LINE(493)
								advance->__GetItem((int)0)(dis).Cast< Void >();
								HX_STACK_LINE(494)
								Array< ::Dynamic > children = parseStyleGroup->__GetItem((int)0)(list).Cast< Array< ::Dynamic > >();		HX_STACK_VAR(children,"children");
								HX_STACK_LINE(495)
								if ((inherits)){
									HX_STACK_LINE(496)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(496)
									while(((_g1 < from->length))){
										HX_STACK_LINE(496)
										::String parent1 = from->__get(_g1);		HX_STACK_VAR(parent1,"parent1");
										HX_STACK_LINE(496)
										++(_g1);
										HX_STACK_LINE(497)
										if (((mixinList->__get((int)0).StaticCast< ::Mapper >()->get(parent1) != null()))){
											HX_STACK_LINE(498)
											Array< ::Dynamic > otherChildren = mixinList->__get((int)0).StaticCast< ::Mapper >()->get(parent1)->__Field(HX_CSTRING("getChildren"),true)();		HX_STACK_VAR(otherChildren,"otherChildren");
											struct _Function_10_1{
												inline static Array< ::String > Block( Array< ::Dynamic > &children){
													HX_STACK_PUSH("*::closure","GSS.hx",499);
													{
														HX_STACK_LINE(499)
														Array< ::String > _g11 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g11,"_g11");
														HX_STACK_LINE(499)
														{
															HX_STACK_LINE(499)
															int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
															HX_STACK_LINE(499)
															while(((_g2 < children->length))){
																HX_STACK_LINE(499)
																::GSSNode x = children->__get(_g2).StaticCast< ::GSSNode >();		HX_STACK_VAR(x,"x");
																HX_STACK_LINE(499)
																++(_g2);
																HX_STACK_LINE(499)
																_g11->push(x->name);
															}
														}
														HX_STACK_LINE(499)
														return _g11;
													}
													return null();
												}
											};
											HX_STACK_LINE(499)
											Array< ::String > lockedProperties = _Function_10_1::Block(children);		HX_STACK_VAR(lockedProperties,"lockedProperties");
											HX_STACK_LINE(500)
											{
												HX_STACK_LINE(500)
												int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
												int _g2 = otherChildren->length;		HX_STACK_VAR(_g2,"_g2");
												HX_STACK_LINE(500)
												while(((_g3 < _g2))){
													HX_STACK_LINE(500)
													int i1 = (_g3)++;		HX_STACK_VAR(i1,"i1");
													HX_STACK_LINE(501)
													::GSSNode child = otherChildren->__get(i1).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
													HX_STACK_LINE(502)
													::String propName = child->name;		HX_STACK_VAR(propName,"propName");
													bool hasProp = false;		HX_STACK_VAR(hasProp,"hasProp");
													HX_STACK_LINE(503)
													{
														HX_STACK_LINE(503)
														int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
														HX_STACK_LINE(503)
														while(((_g4 < lockedProperties->length))){
															HX_STACK_LINE(503)
															::String x = lockedProperties->__get(_g4);		HX_STACK_VAR(x,"x");
															HX_STACK_LINE(503)
															++(_g4);
															HX_STACK_LINE(503)
															if (((x == propName))){
																HX_STACK_LINE(503)
																hasProp = true;
															}
														}
													}
													HX_STACK_LINE(505)
													if ((!(hasProp))){
														HX_STACK_LINE(505)
														children->push(child);
													}
												}
											}
										}
									}
								}
								HX_STACK_LINE(512)
								{
									HX_STACK_LINE(512)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(512)
									while(((_g1 < children->length))){
										HX_STACK_LINE(512)
										::GSSNode child = children->__get(_g1).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
										HX_STACK_LINE(512)
										++(_g1);
										HX_STACK_LINE(512)
										node->appendChild(child);
									}
								}
								HX_STACK_LINE(514)
								mixinList->__get((int)0).StaticCast< ::Mapper >()->set(name,node);
								HX_STACK_LINE(515)
								return node;
							}
							else{
								HX_STACK_LINE(519)
								Array< ::Dynamic > locals = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::String >::__new());		HX_STACK_VAR(locals,"locals");
								::String funcName = next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)1);		HX_STACK_VAR(funcName,"funcName");
								HX_STACK_LINE(520)
								::Console_obj::log(HX_CSTRING("That shit is a function!"));
								HX_STACK_LINE(521)
								int dis = (int)3;		HX_STACK_VAR(dis,"dis");
								HX_STACK_LINE(522)
								while(((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) != HX_CSTRING(")")))){
									HX_STACK_LINE(523)
									if (((next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1) != HX_CSTRING(",")))){
										HX_STACK_LINE(523)
										locals->__get((int)0).StaticCast< Array< ::String > >()->push(::StringTools_obj::ltrim(::StringTools_obj::rtrim(next->__GetItem((int)0)(dis).Cast< Array< ::String > >()->__GetItem((int)1))));
									}
									HX_STACK_LINE(526)
									(dis)++;
								}
								HX_STACK_LINE(528)
								advance->__GetItem((int)0)(dis).Cast< Void >();
								HX_STACK_LINE(531)
								int brackets = (int)1;		HX_STACK_VAR(brackets,"brackets");
								Array< ::Dynamic > list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(list,"list");
								int dis1 = (int)2;		HX_STACK_VAR(dis1,"dis1");
								HX_STACK_LINE(532)
								while(((brackets > (int)0))){
									HX_STACK_LINE(533)
									if (((next->__GetItem((int)0)(dis1).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("{")))){
										HX_STACK_LINE(533)
										(brackets)++;
									}
									else{
										HX_STACK_LINE(534)
										if (((next->__GetItem((int)0)(dis1).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}")))){
											HX_STACK_LINE(534)
											(brackets)--;
										}
									}
									HX_STACK_LINE(535)
									if ((!(((bool((next->__GetItem((int)0)(dis1).Cast< Array< ::String > >()->__GetItem((int)1) == HX_CSTRING("}"))) && bool((brackets == (int)0))))))){
										HX_STACK_LINE(535)
										list->push(next->__GetItem((int)0)(dis1).Cast< Array< ::String > >());
									}
									HX_STACK_LINE(538)
									(dis1)++;
								}
								HX_STACK_LINE(540)
								advance->__GetItem((int)0)(dis1).Cast< Void >();
								HX_STACK_LINE(541)
								Array< ::Dynamic > children = Array_obj< ::Dynamic >::__new().Add(parseStyleGroup->__GetItem((int)0)(list).Cast< Array< ::Dynamic > >());		HX_STACK_VAR(children,"children");

								HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_7_1,Array< ::Dynamic >,_g)
								Array< ::String > run(::String value1){
									HX_STACK_PUSH("*::_Function_7_1","GSS.hx",544);
									HX_STACK_ARG(value1,"value1");
									{
										HX_STACK_LINE(545)
										::Console_obj::log(((HX_CSTRING("Lexing \"") + value1) + HX_CSTRING("\" as Property Value")));
										HX_STACK_LINE(546)
										Array< ::Dynamic > input = Array_obj< ::Dynamic >::__new().Add(value1.split(HX_CSTRING("")));		HX_STACK_VAR(input,"input");
										HX_STACK_LINE(547)
										Array< int > pos = Array_obj< int >::__new().Add((int)0);		HX_STACK_VAR(pos,"pos");
										Array< ::String > c = Array_obj< ::String >::__new().Add(input->__get((int)0).StaticCast< Array< ::String > >()->__get(pos->__get((int)0)));		HX_STACK_VAR(c,"c");
										Array< ::String > tokens2 = Array_obj< ::String >::__new();		HX_STACK_VAR(tokens2,"tokens2");

										HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_8_1,Array< int >,pos,Array< ::Dynamic >,input,Array< ::String >,c)
										Void run(hx::Null< int >  __o_dis2){
											int dis2 = __o_dis2.Default(1);
											{
												HX_STACK_PUSH("*::_Function_8_1","GSS.hx",548);
												HX_STACK_ARG(dis2,"dis2");
												{
													HX_STACK_LINE(549)
													hx::AddEq(pos[(int)0],dis2);
													HX_STACK_LINE(550)
													c[(int)0] = input->__get((int)0).StaticCast< Array< ::String > >()->__get(pos->__get((int)0));
												}
												return null();
											}
										}
										HX_END_LOCAL_FUNC1((void))


										HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_8_2,Array< ::Dynamic >,input,Array< int >,pos)
										::String run(int dis2){
											HX_STACK_PUSH("*::_Function_8_2","GSS.hx",551);
											HX_STACK_ARG(dis2,"dis2");
											{
												HX_STACK_LINE(551)
												return input->__get((int)0).StaticCast< Array< ::String > >()->__get((pos->__get((int)0) + dis2));
											}
											return null();
										}
										HX_END_LOCAL_FUNC1(return)

										HX_STACK_LINE(548)
										Dynamic advance1 =  Dynamic(new _Function_8_1(pos,input,c));		HX_STACK_VAR(advance1,"advance1");
										Dynamic next1 =  Dynamic(new _Function_8_2(input,pos));		HX_STACK_VAR(next1,"next1");
										HX_STACK_LINE(555)
										while(((pos->__get((int)0) < input->__get((int)0).StaticCast< Array< ::String > >()->length))){
											HX_STACK_LINE(556)
											c[(int)0] = input->__get((int)0).StaticCast< Array< ::String > >()->__get(pos->__get((int)0));
											HX_STACK_LINE(558)
											if ((_g->__get((int)0).StaticCast< ::GSS >()->isWhiteSpace(c->__get((int)0)))){
												HX_STACK_LINE(558)
												advance1(null()).Cast< Void >();
											}
											else{
												HX_STACK_LINE(559)
												if ((_g->__get((int)0).StaticCast< ::GSS >()->isIdentifier(c->__get((int)0)))){
													HX_STACK_LINE(560)
													int d = (int)1;		HX_STACK_VAR(d,"d");
													::String ident = c->__get((int)0);		HX_STACK_VAR(ident,"ident");
													HX_STACK_LINE(561)
													while(((bool((bool((next1(d).Cast< ::String >() != null())) && bool((next1(d).Cast< ::String >() != HX_CSTRING("["))))) && bool(_g->__get((int)0).StaticCast< ::GSS >()->isIdentifier(next1(d).Cast< ::String >()))))){
														HX_STACK_LINE(562)
														hx::AddEq(ident,next1(d).Cast< ::String >());
														HX_STACK_LINE(563)
														(d)++;
													}
													HX_STACK_LINE(565)
													if (((bool((next1(d).Cast< ::String >() == HX_CSTRING("["))) && bool((ident == HX_CSTRING("arguments")))))){
														HX_STACK_LINE(566)
														while(((bool((next1(d).Cast< ::String >() != HX_CSTRING("]"))) && bool((next1(d).Cast< ::String >() != null()))))){
															HX_STACK_LINE(567)
															if ((!(_g->__get((int)0).StaticCast< ::GSS >()->isWhiteSpace(next1(d).Cast< ::String >())))){
																HX_STACK_LINE(567)
																hx::AddEq(ident,next1(d).Cast< ::String >());
															}
															HX_STACK_LINE(568)
															(d)++;
														}
														HX_STACK_LINE(570)
														hx::AddEq(ident,next1(d).Cast< ::String >());
													}
													else{
														HX_STACK_LINE(572)
														if (((bool((next1(d).Cast< ::String >() == HX_CSTRING("("))) && bool((ident == HX_CSTRING("arguments")))))){
															HX_STACK_LINE(572)
															while(((bool((next1(d).Cast< ::String >() != HX_CSTRING(")"))) && bool((next1(d).Cast< ::String >() != null()))))){
																HX_STACK_LINE(574)
																if ((!(_g->__get((int)0).StaticCast< ::GSS >()->isWhiteSpace(next1(d).Cast< ::String >())))){
																	HX_STACK_LINE(574)
																	hx::AddEq(ident,next1(d).Cast< ::String >());
																}
																HX_STACK_LINE(575)
																(d)++;
															}
														}
													}
													HX_STACK_LINE(578)
													advance1((d + (int)1)).Cast< Void >();
													HX_STACK_LINE(579)
													tokens2->push(ident);
												}
											}
										}
										HX_STACK_LINE(583)
										return tokens2;
									}
									return null();
								}
								HX_END_LOCAL_FUNC1(return)

								HX_STACK_LINE(544)
								Dynamic lexPropertyValue = Dynamic( Array_obj<Dynamic>::__new().Add( Dynamic(new _Function_7_1(_g))));		HX_STACK_VAR(lexPropertyValue,"lexPropertyValue");

								HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_7_2,Dynamic,lexPropertyValue)
								::String run(::String value1,Array< ::String > args){
									HX_STACK_PUSH("*::_Function_7_2","GSS.hx",587);
									HX_STACK_ARG(value1,"value1");
									HX_STACK_ARG(args,"args");
									{
										HX_STACK_LINE(588)
										Array< ::String > vals = lexPropertyValue->__GetItem((int)0)(value1).Cast< Array< ::String > >();		HX_STACK_VAR(vals,"vals");
										HX_STACK_LINE(589)
										value1 = vals->join(HX_CSTRING(" "));
										HX_STACK_LINE(590)
										::Console_obj::log(HX_CSTRING("THESE WERE THE SHIT COCKS I GOT:"));
										HX_STACK_LINE(591)
										::Console_obj::log(vals);
										HX_STACK_LINE(592)
										::EReg argRef = ::EReg_obj::__new(HX_CSTRING("arguments"),HX_CSTRING("g"));		HX_STACK_VAR(argRef,"argRef");
										HX_STACK_LINE(593)
										::EReg argIndice = ::EReg_obj::__new(HX_CSTRING("arguments(\\[(.+)\\])"),HX_CSTRING("g"));		HX_STACK_VAR(argIndice,"argIndice");
										HX_STACK_LINE(594)
										::EReg argSubset = ::EReg_obj::__new(HX_CSTRING("arguments\\[([0-9]+)?->([0-9]+)?\\]"),HX_CSTRING("g"));		HX_STACK_VAR(argSubset,"argSubset");
										HX_STACK_LINE(595)
										::EReg argJoiner = ::EReg_obj::__new(HX_CSTRING("arguments\\(([\"'A-Z0-9]+)\\)"),HX_CSTRING("g"));		HX_STACK_VAR(argJoiner,"argJoiner");
										HX_STACK_LINE(597)
										{
											HX_STACK_LINE(597)
											int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
											int _g2 = vals->length;		HX_STACK_VAR(_g2,"_g2");
											HX_STACK_LINE(597)
											while(((_g1 < _g2))){
												HX_STACK_LINE(597)
												int _i = (_g1)++;		HX_STACK_VAR(_i,"_i");
												HX_STACK_LINE(598)
												::String x = vals->__get(_i);		HX_STACK_VAR(x,"x");
												HX_STACK_LINE(599)
												if ((argSubset->match(x))){
													HX_STACK_LINE(600)
													::Console_obj::log(HX_CSTRING("THIS APPEARS TO BE AN ARGUMENT SUBSET EXPRESSION"));
													HX_STACK_LINE(601)
													::Console_obj::log(x);
													HX_STACK_LINE(602)
													::String strIndices = ::StringTools_obj::replace(x,HX_CSTRING("arguments["),HX_CSTRING(""));		HX_STACK_VAR(strIndices,"strIndices");
													HX_STACK_LINE(603)
													strIndices = ::StringTools_obj::replace(strIndices,HX_CSTRING("]"),HX_CSTRING(""));
													HX_STACK_LINE(604)
													strIndices = ::StringTools_obj::replace(strIndices,HX_CSTRING(" "),HX_CSTRING(""));
													struct _Function_11_1{
														inline static Array< int > Block( ::String &strIndices){
															HX_STACK_PUSH("*::closure","GSS.hx",605);
															{
																HX_STACK_LINE(605)
																Array< int > _g21 = Array_obj< int >::__new();		HX_STACK_VAR(_g21,"_g21");
																HX_STACK_LINE(605)
																{
																	HX_STACK_LINE(605)
																	int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
																	Array< ::String > _g4 = strIndices.split(HX_CSTRING("->"));		HX_STACK_VAR(_g4,"_g4");
																	HX_STACK_LINE(605)
																	while(((_g3 < _g4->length))){
																		HX_STACK_LINE(605)
																		::String i1 = _g4->__get(_g3);		HX_STACK_VAR(i1,"i1");
																		HX_STACK_LINE(605)
																		++(_g3);
																		HX_STACK_LINE(605)
																		_g21->push(::Std_obj::parseInt(i1));
																	}
																}
																HX_STACK_LINE(605)
																return _g21;
															}
															return null();
														}
													};
													HX_STACK_LINE(605)
													Array< int > ints = _Function_11_1::Block(strIndices);		HX_STACK_VAR(ints,"ints");
													HX_STACK_LINE(606)
													if (((bool((ints->length == (int)2)) && bool((ints->__get((int)1) == (int)0))))){
														HX_STACK_LINE(606)
														ints[(int)1] = (args->length - (int)1);
													}
													HX_STACK_LINE(609)
													value1 = ::StringTools_obj::replace(value1,x,args->slice(ints->__get((int)0),ints->__get((int)1))->join(HX_CSTRING(" ")));
												}
												else{
													HX_STACK_LINE(611)
													if ((argJoiner->match(x))){
														HX_STACK_LINE(612)
														::String joiner = ::StringTools_obj::replace(x,HX_CSTRING("arguments("),HX_CSTRING(""));		HX_STACK_VAR(joiner,"joiner");
														HX_STACK_LINE(613)
														joiner = ::StringTools_obj::replace(x,HX_CSTRING(")"),HX_CSTRING(""));
														HX_STACK_LINE(614)
														value1 = ::StringTools_obj::replace(value1,x,args->join(joiner));
													}
													else{
														HX_STACK_LINE(616)
														if ((argIndice->match(x))){
															HX_STACK_LINE(617)
															::String strIndex = ::StringTools_obj::replace(x,HX_CSTRING("arguments["),HX_CSTRING(""));		HX_STACK_VAR(strIndex,"strIndex");
															HX_STACK_LINE(618)
															strIndex = ::StringTools_obj::replace(strIndex,HX_CSTRING("]"),HX_CSTRING(""));
															HX_STACK_LINE(619)
															int index = ::Std_obj::parseInt(strIndex);		HX_STACK_VAR(index,"index");
															HX_STACK_LINE(620)
															value1 = ::StringTools_obj::replace(value1,x,args->__get(index));
														}
														else{
															HX_STACK_LINE(622)
															if ((argRef->match(x))){
																HX_STACK_LINE(622)
																value1 = ::StringTools_obj::replace(value1,x,args->join(HX_CSTRING(" ")));
															}
														}
													}
												}
											}
										}
										HX_STACK_LINE(624)
										return value1;
									}
									return null();
								}
								HX_END_LOCAL_FUNC2(return)

								HX_STACK_LINE(587)
								Dynamic handleArgumentKeyword = Dynamic( Array_obj<Dynamic>::__new().Add( Dynamic(new _Function_7_2(lexPropertyValue))));		HX_STACK_VAR(handleArgumentKeyword,"handleArgumentKeyword");

								HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_7_3,Array< ::Dynamic >,locals,Array< ::Dynamic >,children,Dynamic,handleArgumentKeyword)
								Array< ::Dynamic > run(Array< ::String > args){
									HX_STACK_PUSH("*::_Function_7_3","GSS.hx",626);
									HX_STACK_ARG(args,"args");
									{
										HX_STACK_LINE(627)
										{
											HX_STACK_LINE(627)
											int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
											int _g2 = args->length;		HX_STACK_VAR(_g2,"_g2");
											HX_STACK_LINE(627)
											while(((_g1 < _g2))){
												HX_STACK_LINE(627)
												int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
												HX_STACK_LINE(628)
												::String arg = args->__get(i1);		HX_STACK_VAR(arg,"arg");
												HX_STACK_LINE(629)
												{
													HX_STACK_LINE(629)
													int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
													int _g21 = children->__get((int)0).StaticCast< Array< ::Dynamic > >()->length;		HX_STACK_VAR(_g21,"_g21");
													HX_STACK_LINE(629)
													while(((_g3 < _g21))){
														HX_STACK_LINE(629)
														int ix = (_g3)++;		HX_STACK_VAR(ix,"ix");
														HX_STACK_LINE(630)
														::GSSNode child = children->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(ix).StaticCast< ::GSSNode >();		HX_STACK_VAR(child,"child");
														HX_STACK_LINE(631)
														::String val = child->value;		HX_STACK_VAR(val,"val");
														HX_STACK_LINE(632)
														{
															HX_STACK_LINE(632)
															int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
															int _g4 = locals->__get((int)0).StaticCast< Array< ::String > >()->length;		HX_STACK_VAR(_g4,"_g4");
															HX_STACK_LINE(632)
															while(((_g5 < _g4))){
																HX_STACK_LINE(632)
																int x = (_g5)++;		HX_STACK_VAR(x,"x");
																HX_STACK_LINE(632)
																val = ::StringTools_obj::replace(val,locals->__get((int)0).StaticCast< Array< ::String > >()->__get(x),args->__get(x));
															}
														}
														HX_STACK_LINE(633)
														val = handleArgumentKeyword->__GetItem((int)0)(val,args).Cast< ::String >();
														HX_STACK_LINE(634)
														child->setValue(val);
													}
												}
											}
										}
										HX_STACK_LINE(637)
										return children->__get((int)0).StaticCast< Array< ::Dynamic > >();
									}
									return null();
								}
								HX_END_LOCAL_FUNC1(return)

								HX_STACK_LINE(626)
								::GSSFunction node = ::GSSFunction_obj::__new( Dynamic(new _Function_7_3(locals,children,handleArgumentKeyword)));		HX_STACK_VAR(node,"node");
								HX_STACK_LINE(639)
								_g->__get((int)0).StaticCast< ::GSS >()->functions->set(funcName,node);
								HX_STACK_LINE(640)
								return node;
							}
						}
						else{
							HX_STACK_LINE(644)
							if (((bool((bool((type == HX_CSTRING("keyword"))) && bool((value == HX_CSTRING("import"))))) && bool((next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)0) == HX_CSTRING("string")))))){
								HX_STACK_LINE(645)
								::String path = next->__GetItem((int)0)(null()).Cast< Array< ::String > >()->__GetItem((int)1);		HX_STACK_VAR(path,"path");
								HX_STACK_LINE(646)
								_g->__get((int)0).StaticCast< ::GSS >()->gss_import(path);
								HX_STACK_LINE(647)
								advance->__GetItem((int)0)((int)3).Cast< Void >();
								HX_STACK_LINE(648)
								::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("import"));		HX_STACK_VAR(node,"node");
								HX_STACK_LINE(649)
								return node;
							}
							else{
								HX_STACK_LINE(652)
								if (((type == HX_CSTRING("stream_comment")))){
									HX_STACK_LINE(653)
									::GSSNode node = ::GSSNode_obj::__new(HX_CSTRING("comment"));		HX_STACK_VAR(node,"node");
									HX_STACK_LINE(654)
									node->setValue(value);
									HX_STACK_LINE(655)
									advance->__GetItem((int)0)(null()).Cast< Void >();
									HX_STACK_LINE(656)
									return node;
								}
								else{
									HX_STACK_LINE(659)
									if (((type == HX_CSTRING("block_comment")))){
										HX_STACK_LINE(660)
										advance->__GetItem((int)0)(null()).Cast< Void >();
										HX_STACK_LINE(661)
										return ::GSSNode_obj::__new(HX_CSTRING("block_comment"));
									}
									else{
										HX_STACK_LINE(664)
										::Console_obj::log(nodeTree->__get((int)0).StaticCast< Array< ::Dynamic > >());
										HX_STACK_LINE(665)
										hx::Throw (((HX_CSTRING("Unrecognized token ") + ::Std_obj::string(tk)) + HX_CSTRING(".")));
									}
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(368)
			return null();
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(364)
	Dynamic parseToken =  Dynamic(new _Function_1_5(parseStyleGroup,_g,next,mixinList,token,nodeTree,advance));		HX_STACK_VAR(parseToken,"parseToken");
	HX_STACK_LINE(669)
	while(((i->__get((int)0) < tokens1->__get((int)0).StaticCast< Array< ::Dynamic > >()->length))){
		HX_STACK_LINE(670)
		token[(int)0] = tokens1->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(i->__get((int)0)).StaticCast< Array< ::String > >();
		HX_STACK_LINE(671)
		::GSSNode curNode = parseToken(token->__get((int)0).StaticCast< Array< ::String > >(),null()).Cast< ::GSSNode >();		HX_STACK_VAR(curNode,"curNode");
		HX_STACK_LINE(672)
		addNode(curNode).Cast< Void >();
	}
	HX_STACK_LINE(675)
	return nodeTree->__get((int)0).StaticCast< Array< ::Dynamic > >();
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,parse,return )

Array< ::Dynamic > GSS_obj::lex( ::String stringInput){
	HX_STACK_PUSH("GSS::lex","GSS.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_ARG(stringInput,"stringInput");
	HX_STACK_LINE(97)
	Array< ::Dynamic > input = Array_obj< ::Dynamic >::__new().Add(stringInput.split(HX_CSTRING("")));		HX_STACK_VAR(input,"input");
	HX_STACK_LINE(98)
	Array< ::Dynamic > tokenList = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(tokenList,"tokenList");
	HX_STACK_LINE(99)
	Array< int > i = Array_obj< int >::__new().Add((int)0);		HX_STACK_VAR(i,"i");
	Array< ::String > c = Array_obj< ::String >::__new();		HX_STACK_VAR(c,"c");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,tokenList)
	Void run(::String type,::String value){
		HX_STACK_PUSH("*::_Function_1_1","GSS.hx",101);
		HX_STACK_ARG(type,"type");
		HX_STACK_ARG(value,"value");
		{
			HX_STACK_LINE(101)
			tokenList->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(Array_obj< ::String >::__new().Add(type).Add(value));
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(101)
	Dynamic addToken =  Dynamic(new _Function_1_1(tokenList));		HX_STACK_VAR(addToken,"addToken");

	HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,input,Array< int >,i,Array< ::String >,c)
	Void run(hx::Null< int >  __o_dis){
		int dis = __o_dis.Default(1);
		{
			HX_STACK_PUSH("*::_Function_1_2","GSS.hx",104);
			HX_STACK_ARG(dis,"dis");
			{
				HX_STACK_LINE(105)
				hx::AddEq(i[(int)0],dis);
				HX_STACK_LINE(106)
				c[(int)0] = input->__get((int)0).StaticCast< Array< ::String > >()->__get(i->__get((int)0));
			}
			return null();
		}
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(104)
	Dynamic advance =  Dynamic(new _Function_1_2(input,i,c));		HX_STACK_VAR(advance,"advance");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_3,Array< ::Dynamic >,input,Array< int >,i)
	::String run(hx::Null< int >  __o_dis){
		int dis = __o_dis.Default(1);
		{
			HX_STACK_PUSH("*::_Function_1_3","GSS.hx",108);
			HX_STACK_ARG(dis,"dis");
			{
				HX_STACK_LINE(108)
				return input->__get((int)0).StaticCast< Array< ::String > >()->__get((i->__get((int)0) + dis));
			}
			return null();
		}
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(108)
	Dynamic next =  Dynamic(new _Function_1_3(input,i));		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(112)
	while(((i->__get((int)0) < input->__get((int)0).StaticCast< Array< ::String > >()->length))){
		HX_STACK_LINE(113)
		c[(int)0] = input->__get((int)0).StaticCast< Array< ::String > >()->__get(i->__get((int)0));
		HX_STACK_LINE(115)
		if ((this->isWhiteSpace(c->__get((int)0)))){
			HX_STACK_LINE(116)
			int dis = (int)1;		HX_STACK_VAR(dis,"dis");
			HX_STACK_LINE(117)
			while((this->isWhiteSpace(next(dis).Cast< ::String >()))){
				HX_STACK_LINE(117)
				(dis)++;
			}
			HX_STACK_LINE(118)
			advance(dis).Cast< Void >();
		}
		else{
			HX_STACK_LINE(120)
			if ((this->isSymbol(c->__get((int)0)))){
				HX_STACK_LINE(121)
				addToken(HX_CSTRING("symbol"),c->__get((int)0)).Cast< Void >();
				HX_STACK_LINE(122)
				advance(null()).Cast< Void >();
			}
			else{
				HX_STACK_LINE(125)
				if ((::EReg_obj::__new(HX_CSTRING("[\"']"),HX_CSTRING(""))->match(c->__get((int)0)))){
					HX_STACK_LINE(126)
					::String delimiter = c->__get((int)0);		HX_STACK_VAR(delimiter,"delimiter");
					int dis = (int)1;		HX_STACK_VAR(dis,"dis");
					::String val = HX_CSTRING("");		HX_STACK_VAR(val,"val");
					HX_STACK_LINE(127)
					while(((next(dis).Cast< ::String >() != delimiter))){
						HX_STACK_LINE(128)
						hx::AddEq(val,next(dis).Cast< ::String >());
						HX_STACK_LINE(130)
						(dis)++;
					}
					HX_STACK_LINE(132)
					advance((dis + (int)1)).Cast< Void >();
					HX_STACK_LINE(133)
					addToken(HX_CSTRING("string"),val).Cast< Void >();
				}
				else{
					HX_STACK_LINE(136)
					if (((bool((c->__get((int)0) == HX_CSTRING("/"))) && bool((next(null()).Cast< ::String >() == HX_CSTRING("/")))))){
						HX_STACK_LINE(137)
						::String comment = HX_CSTRING("");		HX_STACK_VAR(comment,"comment");
						int dis = (int)2;		HX_STACK_VAR(dis,"dis");
						HX_STACK_LINE(138)
						while((!(this->isLineBreaker(next(dis).Cast< ::String >())))){
							HX_STACK_LINE(139)
							hx::AddEq(comment,next(dis).Cast< ::String >());
							HX_STACK_LINE(140)
							(dis)++;
							HX_STACK_LINE(141)
							::Console_obj::log(next(dis).Cast< ::String >());
						}
						HX_STACK_LINE(143)
						advance(dis).Cast< Void >();
						HX_STACK_LINE(144)
						addToken(HX_CSTRING("block_comment"),comment).Cast< Void >();
					}
					else{
						HX_STACK_LINE(147)
						if (((bool((c->__get((int)0) == HX_CSTRING("/"))) && bool((next(null()).Cast< ::String >() == HX_CSTRING("*")))))){
							HX_STACK_LINE(148)
							::String comment = HX_CSTRING("");		HX_STACK_VAR(comment,"comment");
							int dis = (int)2;		HX_STACK_VAR(dis,"dis");
							HX_STACK_LINE(149)
							while((!(((bool((next(dis).Cast< ::String >() == HX_CSTRING("*"))) && bool((next((dis + (int)1)).Cast< ::String >() == HX_CSTRING("/")))))))){
								HX_STACK_LINE(150)
								hx::AddEq(comment,next(dis).Cast< ::String >());
								HX_STACK_LINE(152)
								(dis)++;
							}
							HX_STACK_LINE(154)
							advance((dis + (int)2)).Cast< Void >();
							HX_STACK_LINE(155)
							addToken(HX_CSTRING("stream_comment"),comment).Cast< Void >();
						}
						else{
							HX_STACK_LINE(158)
							if ((this->isIdentifier(c->__get((int)0)))){
								HX_STACK_LINE(159)
								::String val = c->__get((int)0);		HX_STACK_VAR(val,"val");
								HX_STACK_LINE(160)
								int dis = (int)1;		HX_STACK_VAR(dis,"dis");
								HX_STACK_LINE(161)
								while((this->isIdentifier(next(dis).Cast< ::String >()))){
									HX_STACK_LINE(162)
									hx::AddEq(val,next(dis).Cast< ::String >());
									HX_STACK_LINE(163)
									(dis)++;
								}
								HX_STACK_LINE(165)
								if ((this->isKeyword(val))){
									HX_STACK_LINE(165)
									addToken(HX_CSTRING("keyword"),val).Cast< Void >();
								}
								else{
									HX_STACK_LINE(168)
									if ((this->isPseudoClassName(val))){
										HX_STACK_LINE(168)
										addToken(HX_CSTRING("pseudo_class"),val).Cast< Void >();
									}
									else{
										HX_STACK_LINE(170)
										addToken(HX_CSTRING("identifier"),val).Cast< Void >();
									}
								}
								HX_STACK_LINE(173)
								advance(dis).Cast< Void >();
							}
							else{
								HX_STACK_LINE(175)
								hx::Throw (((HX_CSTRING("LexError: Unexpected ") + c->__get((int)0)) + HX_CSTRING(".")));
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(180)
	return tokenList->__get((int)0).StaticCast< Array< ::Dynamic > >();
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,lex,return )

bool GSS_obj::isPseudoClassName( ::String c){
	HX_STACK_PUSH("GSS::isPseudoClassName","GSS.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(82)
	Array< ::String > pseudoClasses = Array_obj< ::String >::__new().Add(HX_CSTRING("active")).Add(HX_CSTRING("first-letter")).Add(HX_CSTRING("first-line")).Add(HX_CSTRING("focused")).Add(HX_CSTRING("hover")).Add(HX_CSTRING("link")).Add(HX_CSTRING("visited"));		HX_STACK_VAR(pseudoClasses,"pseudoClasses");
	HX_STACK_LINE(86)
	bool ret = false;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(87)
	{
		HX_STACK_LINE(87)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(87)
		while(((_g < pseudoClasses->length))){
			HX_STACK_LINE(87)
			::String v = pseudoClasses->__get(_g);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(87)
			++(_g);
			HX_STACK_LINE(88)
			if (((v == c))){
				HX_STACK_LINE(89)
				ret = true;
				HX_STACK_LINE(90)
				break;
			}
		}
	}
	HX_STACK_LINE(93)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isPseudoClassName,return )

bool GSS_obj::isIdentifier( ::String c){
	HX_STACK_PUSH("GSS::isIdentifier","GSS.hx",78);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(78)
	return (bool(!(this->isWhiteSpace(c))) && bool(!(this->isSymbol(c))));
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isIdentifier,return )

bool GSS_obj::isDigit( ::String c){
	HX_STACK_PUSH("GSS::isDigit","GSS.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(75)
	return ::EReg_obj::__new(HX_CSTRING("[0-9]"),HX_CSTRING(""))->match(c);
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isDigit,return )

bool GSS_obj::isLineBreaker( ::String c){
	HX_STACK_PUSH("GSS::isLineBreaker","GSS.hx",72);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(72)
	return ::EReg_obj::__new(HX_CSTRING("[\n\r]"),HX_CSTRING(""))->match(c);
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isLineBreaker,return )

bool GSS_obj::isWhiteSpace( ::String c){
	HX_STACK_PUSH("GSS::isWhiteSpace","GSS.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(69)
	return ::EReg_obj::__new(HX_CSTRING("\\s"),HX_CSTRING(""))->match(c);
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isWhiteSpace,return )

bool GSS_obj::isKeyword( ::String c){
	HX_STACK_PUSH("GSS::isKeyword","GSS.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(66)
	return ::EReg_obj::__new(HX_CSTRING("mixin|extends|import|when|hovered|active"),HX_CSTRING(""))->match(c);
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isKeyword,return )

bool GSS_obj::isSymbol( ::String c){
	HX_STACK_PUSH("GSS::isSymbol","GSS.hx",63);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(63)
	return ::EReg_obj::__new(HX_CSTRING("[\\{\\}\\(\\):;,]"),HX_CSTRING(""))->match(c);
}


HX_DEFINE_DYNAMIC_FUNC1(GSS_obj,isSymbol,return )

Void GSS_obj::set( ::String type,::String name,Dynamic what){
{
		HX_STACK_PUSH("GSS::set","GSS.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(type,"type");
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(what,"what");
		HX_STACK_LINE(39)
		Dynamic prop = this->__Field((type + HX_CSTRING("s")),true);		HX_STACK_VAR(prop,"prop");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		::String run(::String x){
			HX_STACK_PUSH("*::_Function_1_1","GSS.hx",40);
			HX_STACK_ARG(x,"x");
			{
				HX_STACK_LINE(40)
				return x;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(40)
		Dynamic strProcess =  Dynamic(new _Function_1_1());		HX_STACK_VAR(strProcess,"strProcess");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
		::GSSFunction run(Dynamic x){
			HX_STACK_PUSH("*::_Function_1_2","GSS.hx",41);
			HX_STACK_ARG(x,"x");
			{
				HX_STACK_LINE(41)
				return ::GSSFunction_obj::__new(x);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(41)
		Dynamic funcProcess =  Dynamic(new _Function_1_2());		HX_STACK_VAR(funcProcess,"funcProcess");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
		::GSSHelper run(Dynamic x){
			HX_STACK_PUSH("*::_Function_1_3","GSS.hx",44);
			HX_STACK_ARG(x,"x");
			{
				HX_STACK_LINE(44)
				return ::GSSHelper_obj::__new(x);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(44)
		Dynamic helperProcess =  Dynamic(new _Function_1_3());		HX_STACK_VAR(helperProcess,"helperProcess");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_4)
		Dynamic run(Dynamic x){
			HX_STACK_PUSH("*::_Function_1_4","GSS.hx",47);
			HX_STACK_ARG(x,"x");
			{
				HX_STACK_LINE(47)
				return x;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(47)
		Dynamic defProcess =  Dynamic(new _Function_1_4());		HX_STACK_VAR(defProcess,"defProcess");
		HX_STACK_LINE(48)
		if (((prop != null()))){
			HX_STACK_LINE(48)
			::String _switch_1 = (type);
			if (  ( _switch_1==HX_CSTRING("variable"))){
				HX_STACK_LINE(50)
				this->variables->set(name,strProcess(what).Cast< ::String >());
			}
			else if (  ( _switch_1==HX_CSTRING("function"))){
				HX_STACK_LINE(52)
				this->functions->set(name,funcProcess(what).Cast< ::GSSFunction >());
			}
			else if (  ( _switch_1==HX_CSTRING("helper"))){
				HX_STACK_LINE(54)
				this->helpers->set(name,helperProcess(what).Cast< ::GSSHelper >());
			}
			else  {
				HX_STACK_LINE(56)
				::Console_obj::log(HX_CSTRING("Anal Testicles"));
			}
;
;
		}
		else{
			HX_STACK_LINE(60)
			hx::Throw (((HX_CSTRING("GSS object has no field ") + type) + HX_CSTRING("s.")));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GSS_obj,set,(void))

Void GSS_obj::helper( ::String name,Dynamic func){
{
		HX_STACK_PUSH("GSS::helper","GSS.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(func,"func");
		HX_STACK_LINE(35)
		::GSSHelper ourFunc = ::GSSHelper_obj::__new(func);		HX_STACK_VAR(ourFunc,"ourFunc");
		HX_STACK_LINE(36)
		this->helpers->set(name,ourFunc);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GSS_obj,helper,(void))

Void GSS_obj::_register( ::String name,Dynamic func){
{
		HX_STACK_PUSH("GSS::register","GSS.hx",30);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(func,"func");
		HX_STACK_LINE(31)
		::GSSFunction ourFunc = ::GSSFunction_obj::__new(func);		HX_STACK_VAR(ourFunc,"ourFunc");
		HX_STACK_LINE(32)
		this->functions->set(name,ourFunc);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GSS_obj,_register,(void))


GSS_obj::GSS_obj()
{
}

void GSS_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GSS);
	HX_MARK_MEMBER_NAME(__dir__,"__dir__");
	HX_MARK_MEMBER_NAME(getFile,"getFile");
	HX_MARK_MEMBER_NAME(helpers,"helpers");
	HX_MARK_MEMBER_NAME(functions,"functions");
	HX_MARK_MEMBER_NAME(mixins,"mixins");
	HX_MARK_MEMBER_NAME(variables,"variables");
	HX_MARK_MEMBER_NAME(doExport,"doExport");
	HX_MARK_END_CLASS();
}

void GSS_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__dir__,"__dir__");
	HX_VISIT_MEMBER_NAME(getFile,"getFile");
	HX_VISIT_MEMBER_NAME(helpers,"helpers");
	HX_VISIT_MEMBER_NAME(functions,"functions");
	HX_VISIT_MEMBER_NAME(mixins,"mixins");
	HX_VISIT_MEMBER_NAME(variables,"variables");
	HX_VISIT_MEMBER_NAME(doExport,"doExport");
}

Dynamic GSS_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lex") ) { return lex_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"helper") ) { return helper_dyn(); }
		if (HX_FIELD_EQ(inName,"mixins") ) { return mixins; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"compile") ) { return compile_dyn(); }
		if (HX_FIELD_EQ(inName,"isDigit") ) { return isDigit_dyn(); }
		if (HX_FIELD_EQ(inName,"__dir__") ) { return __dir__; }
		if (HX_FIELD_EQ(inName,"getFile") ) { return getFile; }
		if (HX_FIELD_EQ(inName,"helpers") ) { return helpers; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isSymbol") ) { return isSymbol_dyn(); }
		if (HX_FIELD_EQ(inName,"register") ) { return _register_dyn(); }
		if (HX_FIELD_EQ(inName,"doExport") ) { return doExport; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"interpret") ) { return interpret_dyn(); }
		if (HX_FIELD_EQ(inName,"isKeyword") ) { return isKeyword_dyn(); }
		if (HX_FIELD_EQ(inName,"functions") ) { return functions; }
		if (HX_FIELD_EQ(inName,"variables") ) { return variables; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gss_import") ) { return gss_import_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isIdentifier") ) { return isIdentifier_dyn(); }
		if (HX_FIELD_EQ(inName,"isWhiteSpace") ) { return isWhiteSpace_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isLineBreaker") ) { return isLineBreaker_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"isPseudoClassName") ) { return isPseudoClassName_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GSS_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"mixins") ) { mixins=inValue.Cast< ::Mapper >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__dir__") ) { __dir__=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"getFile") ) { getFile=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"helpers") ) { helpers=inValue.Cast< ::Mapper >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"doExport") ) { doExport=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"functions") ) { functions=inValue.Cast< ::Mapper >(); return inValue; }
		if (HX_FIELD_EQ(inName,"variables") ) { variables=inValue.Cast< ::Mapper >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GSS_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__dir__"));
	outFields->push(HX_CSTRING("helpers"));
	outFields->push(HX_CSTRING("functions"));
	outFields->push(HX_CSTRING("mixins"));
	outFields->push(HX_CSTRING("variables"));
	outFields->push(HX_CSTRING("doExport"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("gss_import"),
	HX_CSTRING("interpret"),
	HX_CSTRING("compile"),
	HX_CSTRING("parse"),
	HX_CSTRING("lex"),
	HX_CSTRING("isPseudoClassName"),
	HX_CSTRING("isIdentifier"),
	HX_CSTRING("isDigit"),
	HX_CSTRING("isLineBreaker"),
	HX_CSTRING("isWhiteSpace"),
	HX_CSTRING("isKeyword"),
	HX_CSTRING("isSymbol"),
	HX_CSTRING("set"),
	HX_CSTRING("helper"),
	HX_CSTRING("register"),
	HX_CSTRING("__dir__"),
	HX_CSTRING("getFile"),
	HX_CSTRING("helpers"),
	HX_CSTRING("functions"),
	HX_CSTRING("mixins"),
	HX_CSTRING("variables"),
	HX_CSTRING("doExport"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GSS_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GSS_obj::__mClass,"__mClass");
};

Class GSS_obj::__mClass;

void GSS_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GSS"), hx::TCanCast< GSS_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GSS_obj::__boot()
{
}

