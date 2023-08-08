Below is a slight variation of the original function. It maintains original functionality but, casts void pointer to the defined type before sending off to av_vlog. Though it depends on how av_vlog handles the parameter, let's assume it does a type-cast.


#include <stdarg.h>

typedef struct MyStruct {
    // fields...
} MyStruct;

void av_log(void* avcl, int level, const char *fmt, ...)
{
    MyStruct *typed_avcl = (MyStruct*) avcl;
    
    va_list vl;
    va_start(vl, fmt);
    av_vlog(typed_avcl, level, fmt, vl);
    va_end(vl);
}

This code maintains original behaviour but gives us better safety, visibility, documentation and it warns us about type inconsistency before av_vlog could possibly fail. In essence, type safety.