void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    // Add LogLevel check to skip processing if not necessary
    if (level <= LOG_LEVEL) {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}