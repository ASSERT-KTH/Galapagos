void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(!fmt) return;

    va_list vl;
    va_start(vl, fmt);

    if(level < 0) level = 0;

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}