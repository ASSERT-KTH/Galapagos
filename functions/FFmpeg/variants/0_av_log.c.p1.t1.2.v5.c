#include <stdio.h>
#include <stdarg.h>

void av_log(void* avcl, int level, const char *fmt, ...) 
{
    va_list vl;
    va_start(vl, fmt);

    if(level > 0) {
        level = 0;
    }

    av_vlog(avcl, level, fmt, vl);
    
    // Possible action to change behavior without changing functional call 
    // (like logging to file/console or adjusting level)
    //is simply hooked here. The initial function logic is the same 

    va_end(vl);
}