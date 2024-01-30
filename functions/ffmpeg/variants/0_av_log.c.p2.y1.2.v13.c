void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level >= LOG_DEBUG) // assuming LOG_DEBUG as a predefined log level
    {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}