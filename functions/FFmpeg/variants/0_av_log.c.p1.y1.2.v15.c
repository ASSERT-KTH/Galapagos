Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(fmt)
       av_vlog(avcl, level, fmt, vl);
    
    va_end(vl);
}

Variant 2:

void av_log(void *avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if(avcl)
       av_vlog(avcl, level, fmt, vl);

    va_end(vl);
}

Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(fmt == NULL) return;
    
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

Variant 4:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(avcl == NULL || fmt == NULL) return;
    
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

Variant 5:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt == NULL ? "" : fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}
