void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    av_vlog(avcl, level, fmt, arg);
    va_end(arg);
}