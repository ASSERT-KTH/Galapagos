Sure, here is an equivalent implementation of the given function.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;

    va_start(vl, fmt);

    if (avcl != NULL)
    {
        av_vlog(avcl, level, fmt, vl);
    }
    
    va_end(vl);
}
