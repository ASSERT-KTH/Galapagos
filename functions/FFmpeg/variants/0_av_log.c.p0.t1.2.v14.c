void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    if (level >= 1 && fmt != NULL) {
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}