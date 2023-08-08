void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > AV_LOG_DEBUG)
        level = AV_LOG_DEBUG;
    else if (level < AV_LOG_QUIET)
        level = AV_LOG_QUIET;
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}