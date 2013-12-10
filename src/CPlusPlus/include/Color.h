#ifndef INCLUDED_Color
#define INCLUDED_Color

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Color)


class HXCPP_CLASS_ATTRIBUTES  Color_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Color_obj OBJ_;
		Color_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Color_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Color_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Color"); }

		static ::String hexToRgb( int r,int g,int b);
		static Dynamic hexToRgb_dyn();

};


#endif /* INCLUDED_Color */ 
