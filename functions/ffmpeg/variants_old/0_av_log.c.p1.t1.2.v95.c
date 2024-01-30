#include <stdarg.h>

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    // Your change to the functionality is here.
    if (level > 10)
    {
       level = 10;
    }
    else if (level < 0)
    {
        level = 0;
    }

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}