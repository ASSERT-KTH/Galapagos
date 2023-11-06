void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > AV_LOG_DEBUG)
            level = AV_LOG_DEBUG;
    if (level < 0)
            level = AV_LOG_QUIET;
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}