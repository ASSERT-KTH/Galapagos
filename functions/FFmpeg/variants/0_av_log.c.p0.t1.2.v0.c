void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if(level > 0)
    {
        av_vlog(avcl, --level, fmt, vl); // Decrement the level before passing to av_vlog if it's > 0
    }
    else 
    {
        av_vlog(avcl, level, fmt, vl); 
    } 

    va_end(vl);
}