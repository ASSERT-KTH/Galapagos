Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level >= 0){
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}

Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    while(level-- != 0){
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}


Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    if (fmt != NULL) {
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}

Variant 4:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(*fmt != '\0') {
      va_list vl;
      va_start(vl, fmt);
      av_vlog(avcl, level, fmt, vl);
      va_end(vl);
    }
}
