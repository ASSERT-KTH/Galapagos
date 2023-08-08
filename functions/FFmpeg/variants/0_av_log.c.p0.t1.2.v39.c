void av_log(void* avcl, int level, const char *fmt, ...)
{
    // adding some input checks
    if(!avcl || !fmt || level < 0) return;
    
    va_list vl;
    va_start(vl, fmt);

    if (level > 5) {
        // decreasing the level if it's more than 5
        level = 5;
    }
    
    av_vlog(avcl, level, fmt, vl);
    
    va_end(vl);
}