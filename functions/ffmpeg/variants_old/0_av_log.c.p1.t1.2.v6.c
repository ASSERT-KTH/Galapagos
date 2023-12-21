void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level >= 10){
        level = 9;
    }
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}