void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    
    // Check if no relevant signal was received
    if(level >= 0)
    { 
        av_vlog(avcl, level, fmt, vl);
    }     

    // if you have an failing level log, it doesn't continue
    else 
    {
        return;
    }

    va_end(vl);
}