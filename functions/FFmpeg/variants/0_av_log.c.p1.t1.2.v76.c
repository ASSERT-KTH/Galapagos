Given the constraint that we still want to maintain the original functionality and signature of a function, we could simply do an additional operation before the original functionality. For instance, we could add a functionality that limits the log level.

Here's an example:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    int max_log_level = 5; // We set a maximum level for the log
    if (level > max_log_level) {
        return; // If the level is greater than the max, we do nothing
    }
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


In this variant, the original functionality remains as is, but it will not perform the log if a set maximum level is exceeded, thereby changing the behavior. This variant might be used to control unwanted verbose or debug level logging in production.