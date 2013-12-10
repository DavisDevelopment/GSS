#ifndef INCLUDED_Mapper
#define INCLUDED_Mapper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Mapper)


class HXCPP_CLASS_ATTRIBUTES  Mapper_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Mapper_obj OBJ_;
		Mapper_obj();
		Void __construct(Dynamic ks,Dynamic vs);

	public:
		static hx::ObjectPtr< Mapper_obj > __new(Dynamic ks,Dynamic vs);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Mapper_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mapper"); }

		virtual Void extend( ::Mapper other);
		Dynamic extend_dyn();

		virtual Dynamic get( Dynamic key);
		Dynamic get_dyn();

		virtual Void set( Dynamic key,Dynamic value);
		Dynamic set_dyn();

		Dynamic values;
		Dynamic keys;
};


#endif /* INCLUDED_Mapper */ 
