void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);    
    if (level >= 0) 
    {
        av_vlog(avcl, level, fmt, vl);
    }
    else 
    {  
        av_vlog(avcl, lvl*-1, fmt, vl); 
    }
    va_end(vl);
}