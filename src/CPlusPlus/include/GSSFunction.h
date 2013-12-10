#ifndef INCLUDED_GSSFunction
#define INCLUDED_GSSFunction

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <GSSNode.h>
HX_DECLARE_CLASS0(GSSFunction)
HX_DECLARE_CLASS0(GSSNode)


class HXCPP_CLASS_ATTRIBUTES  GSSFunction_obj : public ::GSSNode_obj{
	public:
		typedef ::GSSNode_obj super;
		typedef GSSFunction_obj OBJ_;
		GSSFunction_obj();
		Void __construct(Dynamic func);

	public:
		static hx::ObjectPtr< GSSFunction_obj > __new(Dynamic func);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GSSFunction_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GSSFunction"); }

		virtual Array< ::Dynamic > __call__( Array< ::String > args);
		Dynamic __call___dyn();

		Dynamic func;
		Dynamic &func_dyn() { return func;}
};


#endif /* INCLUDED_GSSFunction */ 
