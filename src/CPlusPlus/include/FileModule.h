#ifndef INCLUDED_FileModule
#define INCLUDED_FileModule

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(FileModule)


class HXCPP_CLASS_ATTRIBUTES  FileModule_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FileModule_obj OBJ_;
		FileModule_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FileModule_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileModule_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileModule"); }

		static ::String joinPaths( Array< ::String > pathList);
		static Dynamic joinPaths_dyn();

		static ::String getExtension( ::String path);
		static Dynamic getExtension_dyn();

		static ::String getDirectoryName( ::String rawPath);
		static Dynamic getDirectoryName_dyn();

		static Dynamic getContent;
		static inline Dynamic &getContent_dyn() {return getContent; }

		static Dynamic Exists;
		static inline Dynamic &Exists_dyn() {return Exists; }

		static ::String toDataURL( ::String content,::String mime_type);
		static Dynamic toDataURL_dyn();

		static ::String getMimeType( ::String path);
		static Dynamic getMimeType_dyn();

};


#endif /* INCLUDED_FileModule */ 
