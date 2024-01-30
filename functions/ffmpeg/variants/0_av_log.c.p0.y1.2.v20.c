void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list argument_list;
    va_start(argument_list, fmt);
    av_vlog(avcl, level, fmt, argument_list);
    va_end(argument_list);
}