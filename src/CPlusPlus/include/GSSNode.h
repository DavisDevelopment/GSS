#ifndef INCLUDED_GSSNode
#define INCLUDED_GSSNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(GSSNode)
HX_DECLARE_CLASS0(Mapper)


class HXCPP_CLASS_ATTRIBUTES  GSSNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GSSNode_obj OBJ_;
		GSSNode_obj();
		Void __construct(::String type);

	public:
		static hx::ObjectPtr< GSSNode_obj > __new(::String type);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GSSNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GSSNode"); }

		virtual Array< ::Dynamic > getChildren( );
		Dynamic getChildren_dyn();

		virtual ::String getValue( ::Mapper variables,::Mapper mixins);
		Dynamic getValue_dyn();

		virtual Array< ::String > getPrefixes( ::String name);
		Dynamic getPrefixes_dyn();

		virtual Void setValue( ::String val);
		Dynamic setValue_dyn();

		virtual Void setName( ::String name);
		Dynamic setName_dyn();

		virtual Void setParent( ::GSSNode parent);
		Dynamic setParent_dyn();

		virtual Void appendChild( ::GSSNode child);
		Dynamic appendChild_dyn();

		virtual ::String getIndentation( );
		Dynamic getIndentation_dyn();

		Array< ::String > toAppendAfter;
		Array< ::Dynamic > childNodes;
		::GSSNode parent;
		bool hasParent;
		int indents;
		::String value;
		::String name;
		::String type;
};


#endif /* INCLUDED_GSSNode */ 
