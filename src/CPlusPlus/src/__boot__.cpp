#include <hxcpp.h>

#include <sys/io/FileOutput.h>
#include <sys/io/File.h>
#include <sys/FileSystem.h>
#include <haxe/io/Output.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/Bytes.h>
#include <haxe/ds/StringMap.h>
#include <haxe/Log.h>
#include <Sys.h>
#include <StringTools.h>
#include <Std.h>
#include <Mapper.h>
#include <IMap.h>
#include <Main.h>
#include <Helpers.h>
#include <GSSHelper.h>
#include <GSSFunction.h>
#include <GSSNode.h>
#include <GSS.h>
#include <Console.h>
#include <FileModule.h>
#include <EReg.h>
#include <cpp/Lib.h>
#include <Color.h>
#include <Builtins.h>
#include <Base64.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sys::io::FileOutput_obj::__register();
::sys::io::File_obj::__register();
::sys::FileSystem_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::Log_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::Std_obj::__register();
::Mapper_obj::__register();
::IMap_obj::__register();
::Main_obj::__register();
::Helpers_obj::__register();
::GSSHelper_obj::__register();
::GSSFunction_obj::__register();
::GSSNode_obj::__register();
::GSS_obj::__register();
::Console_obj::__register();
::FileModule_obj::__register();
::EReg_obj::__register();
::cpp::Lib_obj::__register();
::Color_obj::__register();
::Builtins_obj::__register();
::Base64_obj::__register();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::haxe::Log_obj::__boot();
::Base64_obj::__boot();
::Builtins_obj::__boot();
::Color_obj::__boot();
::FileModule_obj::__boot();
::Console_obj::__boot();
::GSS_obj::__boot();
::GSSNode_obj::__boot();
::GSSFunction_obj::__boot();
::GSSHelper_obj::__boot();
::Helpers_obj::__boot();
::Main_obj::__boot();
::IMap_obj::__boot();
::Mapper_obj::__boot();
::Std_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::FileSystem_obj::__boot();
::sys::io::File_obj::__boot();
::sys::io::FileOutput_obj::__boot();
}

