void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list myArgs;
    va_start(myArgs, fmt);
    av_vlog(avcl, level, fmt, myArgs);
    va_end(myArgs);
}