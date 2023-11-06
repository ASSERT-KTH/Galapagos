void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list arguments;
    va_start(arguments, fmt);
    av_vlog(avcl, level, fmt, arguments);
    va_end(arguments);
}