Here is a variant where any `NULL` pointer passed as the first argument doesn't start the variable argument list processing, yet it slightly changes the behavior without significantly compromising the key feature provided initially - logging information based on level with variable argument format.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    if(avcl != NULL)
    {
        va_start(vl, fmt);  
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}
