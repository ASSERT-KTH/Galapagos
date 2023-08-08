void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 0)
    {   
        av_vlog(avcl, level, fmt, vl);
    }
    else // If level not greater than 0, use a default value, for instance 1.
    {
        av_vlog(avcl, 1, fmt, vl);
    }
        
    va_end(vl);
}