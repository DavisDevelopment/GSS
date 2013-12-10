#ifndef INCLUDED_Console
#define INCLUDED_Console

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Console)


class HXCPP_CLASS_ATTRIBUTES  Console_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Console_obj OBJ_;
		Console_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Console_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Console_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Console"); }

		static Void log( Dynamic x);
		static Dynamic log_dyn();

};


#endif /* INCLUDED_Console */ 
