void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level < 1) // Behavior changes as per level
    {
        level = 1; // Min level put to 1
    }
    av_vlog(avcl, level, fmt, vl); 
    va_end(vl);
}