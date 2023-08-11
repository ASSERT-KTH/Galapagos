#include <stdio.h>
#include <stdarg.h>

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    printf("Calling av_vlog with level %d.\n", level);  // Added line
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}