void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (level >= 0) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}