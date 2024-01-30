Here's a program variant that also validates some of the function's inputs:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (avcl == NULL || fmt == NULL)
        return;

    if (level < 0 || level > 5) 
        return; 

    va_list vl;
    va_start(vl, fmt);

    if (strnlen(fmt, 500) > 499) 
    {
        va_end(vl);
        return;
    }
    
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}
