Version 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (fmt != NULL)
    {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}

Version 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt == NULL)
    {
        return;
    }

    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

Version 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    
    if (fmt != NULL)
    {
        va_start(vl, fmt);
    }

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

Version 4:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;

    int use_default = (fmt == NULL);
    const char *message = use_default ? "Null string" : fmt;
    
    va_start(vl, message);
    av_vlog(avcl, level, message, vl);
    va_end(vl); 
}
