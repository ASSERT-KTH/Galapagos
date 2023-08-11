void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt == NULL || avcl == NULL)
        return;
    
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}