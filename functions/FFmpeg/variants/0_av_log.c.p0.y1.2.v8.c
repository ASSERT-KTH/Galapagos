void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list argList;
    va_start(argList, fmt);
    av_vlog(avcl, level, fmt, argList);
    va_end(argList);
}