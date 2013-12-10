#include <hxcpp.h>

#ifndef INCLUDED_Base64
#include <Base64.h>
#endif
#ifndef INCLUDED_FileModule
#include <FileModule.h>
#endif
#ifndef INCLUDED_Mapper
#include <Mapper.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

Void FileModule_obj::__construct()
{
	return null();
}

FileModule_obj::~FileModule_obj() { }

Dynamic FileModule_obj::__CreateEmpty() { return  new FileModule_obj; }
hx::ObjectPtr< FileModule_obj > FileModule_obj::__new()
{  hx::ObjectPtr< FileModule_obj > result = new FileModule_obj();
	result->__construct();
	return result;}

Dynamic FileModule_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileModule_obj > result = new FileModule_obj();
	result->__construct();
	return result;}

::String FileModule_obj::joinPaths( Array< ::String > pathList){
	HX_STACK_PUSH("FileModule::joinPaths","FileModule.hx",4);
	HX_STACK_ARG(pathList,"pathList");
	HX_STACK_LINE(5)
	::String path = HX_CSTRING("");		HX_STACK_VAR(path,"path");
	HX_STACK_LINE(6)
	{
		HX_STACK_LINE(6)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = pathList->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(6)
		while(((_g1 < _g))){
			HX_STACK_LINE(6)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(7)
			::String p = pathList->__get(i);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(8)
			hx::AddEq(path,::StringTools_obj::replace(p,HX_CSTRING("\\"),HX_CSTRING("/")));
			HX_STACK_LINE(9)
			if (((bool((path.substring((path.length - (int)2),(path.length - (int)1)) != HX_CSTRING("/"))) && bool((i != (pathList->length - (int)1)))))){
				HX_STACK_LINE(9)
				hx::AddEq(path,HX_CSTRING("/"));
			}
		}
	}
	HX_STACK_LINE(11)
	return path;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileModule_obj,joinPaths,return )

::String FileModule_obj::getExtension( ::String path){
	HX_STACK_PUSH("FileModule::getExtension","FileModule.hx",13);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(13)
	return path.substring(path.lastIndexOf(HX_CSTRING("."),null()),path.length);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileModule_obj,getExtension,return )

::String FileModule_obj::getDirectoryName( ::String rawPath){
	HX_STACK_PUSH("FileModule::getDirectoryName","FileModule.hx",16);
	HX_STACK_ARG(rawPath,"rawPath");
	HX_STACK_LINE(17)
	::String path = ::StringTools_obj::replace(rawPath,HX_CSTRING("\\"),HX_CSTRING("/"));		HX_STACK_VAR(path,"path");
	HX_STACK_LINE(18)
	return path.substring((int)0,(path.lastIndexOf(HX_CSTRING("/"),null()) + (int)1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileModule_obj,getDirectoryName,return )

HX_BEGIN_DEFAULT_FUNC(__default_getContent,FileModule_obj)
::String run(::String path){
	HX_STACK_PUSH("FileModule::getContent","FileModule.hx",20);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(22)
	return ::sys::io::File_obj::getContent(path);
	HX_STACK_LINE(24)
	return HX_CSTRING("");
}
HX_END_LOCAL_FUNC1(return )
HX_END_DEFAULT_FUNC

Dynamic FileModule_obj::getContent;

HX_BEGIN_DEFAULT_FUNC(__default_Exists,FileModule_obj)
bool run(::String path){
	HX_STACK_PUSH("FileModule::Exists","FileModule.hx",26);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(28)
	return ::sys::FileSystem_obj::sys_exists(path);
	HX_STACK_LINE(30)
	return true;
}
HX_END_LOCAL_FUNC1(return )
HX_END_DEFAULT_FUNC

Dynamic FileModule_obj::Exists;

::String FileModule_obj::toDataURL( ::String content,::String mime_type){
	HX_STACK_PUSH("FileModule::toDataURL","FileModule.hx",32);
	HX_STACK_ARG(content,"content");
	HX_STACK_ARG(mime_type,"mime_type");
	HX_STACK_LINE(33)
	::String encodedData = ::Base64_obj::encode(content);		HX_STACK_VAR(encodedData,"encodedData");
	HX_STACK_LINE(34)
	return (((HX_CSTRING("data:") + mime_type) + HX_CSTRING(";base64,")) + encodedData);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FileModule_obj,toDataURL,return )

::String FileModule_obj::getMimeType( ::String path){
	HX_STACK_PUSH("FileModule::getMimeType","FileModule.hx",36);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(37)
	Array< ::String > fileExtensions = Array_obj< ::String >::__new().Add(HX_CSTRING(".jpg")).Add(HX_CSTRING(".jpeg")).Add(HX_CSTRING(".png")).Add(HX_CSTRING(".bmp")).Add(HX_CSTRING(".gif")).Add(HX_CSTRING(".svg"));		HX_STACK_VAR(fileExtensions,"fileExtensions");
	HX_STACK_LINE(40)
	Array< ::String > mimeTypes = Array_obj< ::String >::__new().Add(HX_CSTRING("image/jpeg")).Add(HX_CSTRING("image/jpeg")).Add(HX_CSTRING("image/png")).Add(HX_CSTRING("image/bmp")).Add(HX_CSTRING("image/gif")).Add(HX_CSTRING("image/svg+xml"));		HX_STACK_VAR(mimeTypes,"mimeTypes");
	HX_STACK_LINE(43)
	::Mapper mimeTypeGetter = ::Mapper_obj::__new(fileExtensions,mimeTypes);		HX_STACK_VAR(mimeTypeGetter,"mimeTypeGetter");
	HX_STACK_LINE(44)
	::String extension = ::FileModule_obj::getExtension(path);		HX_STACK_VAR(extension,"extension");
	HX_STACK_LINE(45)
	return (  (((mimeTypeGetter->get(extension) != null()))) ? ::String(mimeTypeGetter->get(extension)) : ::String(HX_CSTRING("applicaton/octet-stream")) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileModule_obj,getMimeType,return )


FileModule_obj::FileModule_obj()
{
}

void FileModule_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileModule);
	HX_MARK_END_CLASS();
}

void FileModule_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic FileModule_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Exists") ) { return Exists; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"joinPaths") ) { return joinPaths_dyn(); }
		if (HX_FIELD_EQ(inName,"toDataURL") ) { return toDataURL_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getContent") ) { return getContent; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getMimeType") ) { return getMimeType_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getExtension") ) { return getExtension_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getDirectoryName") ) { return getDirectoryName_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileModule_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Exists") ) { Exists=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getContent") ) { getContent=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileModule_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("joinPaths"),
	HX_CSTRING("getExtension"),
	HX_CSTRING("getDirectoryName"),
	HX_CSTRING("getContent"),
	HX_CSTRING("Exists"),
	HX_CSTRING("toDataURL"),
	HX_CSTRING("getMimeType"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileModule_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileModule_obj::getContent,"getContent");
	HX_MARK_MEMBER_NAME(FileModule_obj::Exists,"Exists");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileModule_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileModule_obj::getContent,"getContent");
	HX_VISIT_MEMBER_NAME(FileModule_obj::Exists,"Exists");
};

Class FileModule_obj::__mClass;

void FileModule_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("FileModule"), hx::TCanCast< FileModule_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileModule_obj::__boot()
{
	getContent = new __default_getContent;

	Exists = new __default_Exists;

}

