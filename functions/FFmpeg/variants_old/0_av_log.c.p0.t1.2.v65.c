In this variant, the function checks if the log level is too high before invoking the av_vlog() function. It can provide a way to filter and manage log outputs according to their severity levels.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level > 5)
    {
       return;
    }

    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}
