void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 0) {
        av_vlog(avcl, level, fmt, vl);
    } else {
        av_vlog(avcl, 10, "Changed to default level. Original message: %s", fmt, vl);
    }
    va_end(vl);
}