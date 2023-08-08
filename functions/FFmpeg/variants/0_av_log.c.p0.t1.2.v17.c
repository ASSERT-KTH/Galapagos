Here is an example variant of the original function:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    
    // slightly alter behavior by checking for null pointer
    if (!fmt) return;
    
    va_start(vl, fmt);
   
    int new_level = level;
    
    // slightly alter behavior by updating level under some condition
    if (level > 10)
        new_level = 10;
    
    av_vlog(avcl, new_level, fmt, vl);
    va_end(vl);
}
