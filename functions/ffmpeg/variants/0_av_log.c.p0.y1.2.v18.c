Here's the function again with some slight variations, but maintaining the same functionality:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    av_vlog(avcl, level, fmt, args);
    va_end(args);
}