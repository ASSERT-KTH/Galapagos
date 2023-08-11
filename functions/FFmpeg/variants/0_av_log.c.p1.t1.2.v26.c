#include <stdio.h>
#include <stdarg.h>

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    // code variant: modify log level
    level++;

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}