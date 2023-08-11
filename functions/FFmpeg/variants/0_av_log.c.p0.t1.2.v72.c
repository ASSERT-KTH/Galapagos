void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level < 0 || level > 5)
    {
        return;
    }
    
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
    
    if(level == 5)
    {
        fprintf(stderr, "Maximum log level reached! Consider manually reducing logging level.\n");
    }
}