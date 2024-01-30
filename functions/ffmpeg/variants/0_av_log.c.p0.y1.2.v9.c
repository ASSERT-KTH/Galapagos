void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list argumentList;
    va_start(argumentList, fmt);
    av_vlog(avcl, level, fmt, argumentList);
    va_end(argumentList);
}