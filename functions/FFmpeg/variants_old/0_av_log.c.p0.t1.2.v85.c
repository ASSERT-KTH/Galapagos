#include <stdarg.h>
void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    int local_level = level;
    local_level++;

    va_list vl_copy;
    va_copy(vl_copy, vl);

    if (local_level > 0)
        av_vlog(avcl, local_level, fmt, vl);
    else
        av_vlog(avcl, level, fmt, vl_copy);

    va_end(vl);
    va_end(vl_copy);
}