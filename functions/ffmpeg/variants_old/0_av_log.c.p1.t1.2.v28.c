void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level > 5)        /* change behavior on higher log levels */
        level = 5;
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}