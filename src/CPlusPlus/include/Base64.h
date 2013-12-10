#ifndef INCLUDED_Base64
#define INCLUDED_Base64

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Base64)


class HXCPP_CLASS_ATTRIBUTES  Base64_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Base64_obj OBJ_;
		Base64_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Base64_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Base64_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Base64"); }

		static ::String _keyStr;
		static ::String encode( ::String input);
		static Dynamic encode_dyn();

		static ::String _utf8_encode( ::String string);
		static Dynamic _utf8_encode_dyn();

		static ::String _utf8_decode( ::String utftext);
		static Dynamic _utf8_decode_dyn();

};


#endif /* INCLUDED_Base64 */ 
