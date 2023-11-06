void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list arglist;
    va_start(arglist, fmt);
    av_vlog(avcl, level, fmt, arglist);
    va_end(arglist);
}