#include <dlfcn.h>
#include <Logger.h>
#include <obfuscate.h>
#include "il2cpp-appdata.h"
#include "il2cpp-init.h"

#include <SafeString.h>
#include "../Const/Const_Il2cpp.h"

#define DO_API(r, n, p) r (*n) p
#include "il2cpp-api-functions.h"
#undef DO_API

void *il2cpp_handle = NULL;

void init_il2cpp_api()
{
    LOGD("handle = %p", il2cpp_handle);
    #define DO_API(r, n, p) n = (r (*) p)dlsym(il2cpp_handle, SAFE_CSTR(Const::Il2cpp::n))
    #include "il2cpp-api-functions.h"
    #undef DO_API
}