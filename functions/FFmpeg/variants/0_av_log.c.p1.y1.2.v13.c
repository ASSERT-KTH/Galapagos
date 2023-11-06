Variant 1

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if(vl != NULL)
        av_vlog(avcl, level, fmt, vl);

    va_end(vl);
}


Variant 2

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(avcl != NULL && fmt != NULL) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}


Variant 3

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl_tmp;
    va_start(vl_tmp, fmt);
    if(vl_tmp != NULL) {
        av_vlog(avcl, level, fmt, vl_tmp);
    }
    va_end(vl_tmp);
}


Variant 4

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(fmt != NULL) {
        va_list vl_tmp;
        va_start(vl_tmp, fmt);
        av_vlog(avcl, level, fmt, vl_tmp);
        va_end(vl_tmp);
    }
}


Variant 5

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(avcl != NULL && level > 0 ) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}
