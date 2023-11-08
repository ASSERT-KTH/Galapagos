1.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    va_list vl_copy;
    va_copy(vl_copy, vl);
    av_vlog(avcl, level, fmt, vl_copy);
    va_end(vl_copy);
    va_end(vl);
}

2.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if (level > -1) {
      av_vlog(avcl, level, fmt, vl);
    }

    va_end(vl);
}

3.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;

    if (fmt != NULL) {
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);    
    }
}