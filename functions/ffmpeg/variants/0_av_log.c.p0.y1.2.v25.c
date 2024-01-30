Sure, Here is an alternative implementation. This version makes use of the standard vfprintf function and stdio stream manipulations.


#include <stdio.h>
#include <stdarg.h>
void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    if(level <= LOG_LEVEL){
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
    }

    va_end(args);
}


Please note: 

1. This version doesn't take into account the 'avcl' variable at all since the original code snippet also didn't use it. 
2. This implementation will output everything to the error stream.
3. The "LOG_LEVEL" refers to an external predefined constant which specifies the minimal level of log to be shown, which actually shall be defined somewhere else. It's represented according to its common appearance in such logging functions.
4. It introduces a newline ("\n") after each log, which can be removed if not needed.