The reference implementation is a variadic function, meaning it can accept a variable number of arguments. In the variant below, a condition is added to only process the function if the log level is less than or equal to a maximum log level.

Here is a variant:


#define MAX_LOG_LEVEL 5

void av_log(void * avcl, int level, const char *fmt, ...)
{
    if (level <= MAX_LOG_LEVEL) 
    { 
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    } 
}

In this variant, it's checked if a passed log level `level` value is less than or equal to the set maximum log level (`MAX_LOG_LEVEL`). If the level is greater, this version of `av_log` simply does nothing, thereby changing the function's behavior that all log messages were getting through irrespective of the log level in the original implementation. Implementing the maximum log level may benefit in controlling verbosity of logging such as only logging error (and other higher critical level) messages while debugging.