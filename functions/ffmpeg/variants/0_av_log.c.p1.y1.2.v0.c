1.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 0) {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}


2.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (avcl != NULL && fmt != NULL) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}


3.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt == NULL)
        return;

    va_list vl;
    va_start(vl, fmt);
    if (level > 0 && avcl != NULL)
        av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


4.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level >= LOG_LEVEL && avcl != NULL) {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}

5.

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (avcl && fmt && level > LOG_LEVEL) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}
