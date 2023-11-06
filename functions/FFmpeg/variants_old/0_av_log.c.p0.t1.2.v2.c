void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level > 10) {
        av_vlog(avcl, 10, fmt, vl);
    } else {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}