#ifndef INCLUDED_GSS
#define INCLUDED_GSS

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(GSS)
HX_DECLARE_CLASS0(GSSNode)
HX_DECLARE_CLASS0(Mapper)


class HXCPP_CLASS_ATTRIBUTES  GSS_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GSS_obj OBJ_;
		GSS_obj();
		Void __construct(Dynamic getFile,::String dir,Dynamic __o_doExport);

	public:
		static hx::ObjectPtr< GSS_obj > __new(Dynamic getFile,::String dir,Dynamic __o_doExport);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GSS_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GSS"); }

		virtual Void gss_import( ::String path);
		Dynamic gss_import_dyn();

		virtual Void interpret( Array< ::Dynamic > ast);
		Dynamic interpret_dyn();

		virtual ::String compile( Array< ::Dynamic > ast);
		Dynamic compile_dyn();

		virtual Array< ::Dynamic > parse( Array< ::Dynamic > tokens);
		Dynamic parse_dyn();

		virtual Array< ::Dynamic > lex( ::String stringInput);
		Dynamic lex_dyn();

		virtual bool isPseudoClassName( ::String c);
		Dynamic isPseudoClassName_dyn();

		virtual bool isIdentifier( ::String c);
		Dynamic isIdentifier_dyn();

		virtual bool isDigit( ::String c);
		Dynamic isDigit_dyn();

		virtual bool isLineBreaker( ::String c);
		Dynamic isLineBreaker_dyn();

		virtual bool isWhiteSpace( ::String c);
		Dynamic isWhiteSpace_dyn();

		virtual bool isKeyword( ::String c);
		Dynamic isKeyword_dyn();

		virtual bool isSymbol( ::String c);
		Dynamic isSymbol_dyn();

		virtual Void set( ::String type,::String name,Dynamic what);
		Dynamic set_dyn();

		virtual Void helper( ::String name,Dynamic func);
		Dynamic helper_dyn();

		virtual Void _register( ::String name,Dynamic func);
		Dynamic _register_dyn();

		::String __dir__;
		Dynamic getFile;
		Dynamic &getFile_dyn() { return getFile;}
		::Mapper helpers;
		::Mapper functions;
		::Mapper mixins;
		::Mapper variables;
		bool doExport;
};


#endif /* INCLUDED_GSS */ 
