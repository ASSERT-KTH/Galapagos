void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    av_vlog(avcl, level, fmt, ap);
    va_end(ap);
}