void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if (level > 0) {
        av_vlog(avcl, level, fmt, vl);
    } else {
        av_vlog(avcl, 1, fmt, vl);  // Change behavior: even if level is not > 0, it's still gonna be logged
    }

    va_end(vl);
}