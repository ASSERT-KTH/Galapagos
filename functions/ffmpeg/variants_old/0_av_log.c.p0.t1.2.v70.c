void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if (level > 0) {
        level = 0;
    }
    av_vlog(avcl, level, fmt, vl);

    va_end(vl);

    // just in case logic fails, returns error code -1
    return -1;
}