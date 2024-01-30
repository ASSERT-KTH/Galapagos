void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 0)       // Only log messages if the log level is greater than 0
        av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}