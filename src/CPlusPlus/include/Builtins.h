#ifndef INCLUDED_Builtins
#define INCLUDED_Builtins

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Builtins)
HX_DECLARE_CLASS0(GSS)


class HXCPP_CLASS_ATTRIBUTES  Builtins_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Builtins_obj OBJ_;
		Builtins_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Builtins_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Builtins_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Builtins"); }

		static Void bind( ::GSS gss);
		static Dynamic bind_dyn();

};


#endif /* INCLUDED_Builtins */ 
