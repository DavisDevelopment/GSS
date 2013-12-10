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
#ifndef INCLUDED_Helpers
#include <Helpers.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::main( ){
{
		HX_STACK_PUSH("Main::main","Main.hx",3);
		HX_STACK_LINE(12)
		Array< ::String > args = ::Sys_obj::args();		HX_STACK_VAR(args,"args");
		HX_STACK_LINE(13)
		Array< ::String > __path__ = Array_obj< ::String >::__new().Add(HX_CSTRING(""));		HX_STACK_VAR(__path__,"__path__");
		HX_STACK_LINE(14)
		::String input = HX_CSTRING("");		HX_STACK_VAR(input,"input");
		::String cwd = ::Sys_obj::getCwd();		HX_STACK_VAR(cwd,"cwd");
		HX_STACK_LINE(15)
		if (((args->length >= (int)1))){
			HX_STACK_LINE(16)
			::String initPath = args->__get((int)0);		HX_STACK_VAR(initPath,"initPath");
			HX_STACK_LINE(17)
			::String path = ::StringTools_obj::replace((cwd + initPath),HX_CSTRING("\\"),HX_CSTRING("/"));		HX_STACK_VAR(path,"path");
			HX_STACK_LINE(18)
			__path__[(int)0] = path;
			HX_STACK_LINE(19)
			if ((::sys::FileSystem_obj::sys_exists(path))){
				HX_STACK_LINE(19)
				input = ::sys::io::File_obj::getContent(path);
			}
			else{
				HX_STACK_LINE(21)
				hx::Throw (((HX_CSTRING("IOError: Could not find file ") + path) + HX_CSTRING(".")));
			}
		}
		else{
			HX_STACK_LINE(25)
			input = HX_CSTRING(".element { padding: 14px; margin: 20px; width:  960px; }");
		}

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,__path__)
		::String run(::String initPath){
			HX_STACK_PUSH("*::_Function_1_1","Main.hx",29);
			HX_STACK_ARG(initPath,"initPath");
			{
				HX_STACK_LINE(30)
				Array< ::String > broken = __path__->__get((int)0).split(HX_CSTRING("/"));		HX_STACK_VAR(broken,"broken");
				HX_STACK_LINE(31)
				::String dirPath = broken->slice((int)0,(broken->length - (int)1))->join(HX_CSTRING("/"));		HX_STACK_VAR(dirPath,"dirPath");
				HX_STACK_LINE(32)
				::String path = ::StringTools_obj::replace(((dirPath + HX_CSTRING("/")) + initPath),HX_CSTRING("\\"),HX_CSTRING("/"));		HX_STACK_VAR(path,"path");
				HX_STACK_LINE(33)
				::haxe::Log_obj::trace(HX_CSTRING("Importing File From:"),hx::SourceInfo(HX_CSTRING("Main.hx"),33,HX_CSTRING("Main"),HX_CSTRING("main")));
				HX_STACK_LINE(34)
				::haxe::Log_obj::trace(path,hx::SourceInfo(HX_CSTRING("Main.hx"),34,HX_CSTRING("Main"),HX_CSTRING("main")));
				HX_STACK_LINE(35)
				if ((::sys::FileSystem_obj::sys_exists(path))){
					HX_STACK_LINE(36)
					::String content = ::sys::io::File_obj::getContent(path);		HX_STACK_VAR(content,"content");
					HX_STACK_LINE(37)
					::haxe::Log_obj::trace(content,hx::SourceInfo(HX_CSTRING("Main.hx"),37,HX_CSTRING("Main"),HX_CSTRING("main")));
					HX_STACK_LINE(38)
					return content;
				}
				else{
					HX_STACK_LINE(39)
					hx::Throw (((((HX_CSTRING("ImportError:  Could not 'import' ") + initPath) + HX_CSTRING(" from ")) + dirPath) + HX_CSTRING(".")));
				}
				HX_STACK_LINE(35)
				return null();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(29)
		Dynamic getFile =  Dynamic(new _Function_1_1(__path__));		HX_STACK_VAR(getFile,"getFile");
		HX_STACK_LINE(43)
		::GSS gss = ::GSS_obj::__new(getFile,__path__->__get((int)0),true);		HX_STACK_VAR(gss,"gss");
		HX_STACK_LINE(44)
		::Helpers_obj::bind(gss);
		HX_STACK_LINE(45)
		::Builtins_obj::bind(gss);
		HX_STACK_LINE(46)
		Array< ::Dynamic > tokens = gss->lex(input);		HX_STACK_VAR(tokens,"tokens");
		HX_STACK_LINE(47)
		::haxe::Log_obj::trace(tokens,hx::SourceInfo(HX_CSTRING("Main.hx"),47,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(48)
		Array< ::Dynamic > ast = gss->parse(tokens);		HX_STACK_VAR(ast,"ast");
		HX_STACK_LINE(49)
		::haxe::Log_obj::trace(ast,hx::SourceInfo(HX_CSTRING("Main.hx"),49,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(50)
		::String css = gss->compile(ast);		HX_STACK_VAR(css,"css");
		HX_STACK_LINE(51)
		if (((args->length == (int)1))){
			HX_STACK_LINE(51)
			::haxe::Log_obj::trace(css,hx::SourceInfo(HX_CSTRING("Main.hx"),52,HX_CSTRING("Main"),HX_CSTRING("main")));
		}
		else{
			HX_STACK_LINE(54)
			if (((args->length == (int)2))){
				HX_STACK_LINE(55)
				::String initPath = args->__get((int)1);		HX_STACK_VAR(initPath,"initPath");
				::String writePath = ::StringTools_obj::replace((cwd + initPath),HX_CSTRING("\\"),HX_CSTRING("/"));		HX_STACK_VAR(writePath,"writePath");
				HX_STACK_LINE(56)
				::sys::io::File_obj::saveContent(writePath,css);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

