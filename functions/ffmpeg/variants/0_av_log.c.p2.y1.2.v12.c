void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 50)
        return; 
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}