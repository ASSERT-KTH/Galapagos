Adding a functionality to print the log only when the log level is below a certain threshold.


#include <stdio.h>

void av_log(void* avcl, int level, const char *fmt, ...)
{
    const int log_level_threshold = 5;
    if(level > log_level_threshold) return;

    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


This version of `av_log` would filter out logs that are above a specific severity level. While the nature of this change substantially depends on the meaning of `level` parameter, it's just an example. The change preserves the original functionality by still correctly formatting, sending out logs and covering all levels under `log_level_threshold`.