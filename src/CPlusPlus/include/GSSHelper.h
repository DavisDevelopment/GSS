#ifndef INCLUDED_GSSHelper
#define INCLUDED_GSSHelper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <GSSNode.h>
HX_DECLARE_CLASS0(GSSHelper)
HX_DECLARE_CLASS0(GSSNode)


class HXCPP_CLASS_ATTRIBUTES  GSSHelper_obj : public ::GSSNode_obj{
	public:
		typedef ::GSSNode_obj super;
		typedef GSSHelper_obj OBJ_;
		GSSHelper_obj();
		Void __construct(Dynamic rawFunc);

	public:
		static hx::ObjectPtr< GSSHelper_obj > __new(Dynamic rawFunc);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GSSHelper_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GSSHelper"); }

		virtual ::String __call__( Array< ::String > args);
		Dynamic __call___dyn();

		Dynamic func;
		Dynamic &func_dyn() { return func;}
};


#endif /* INCLUDED_GSSHelper */ 
