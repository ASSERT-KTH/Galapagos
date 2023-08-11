Here is a function variant that performs the same functionality with slight behavior variations:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;

    if (!fmt || level < 0) {
        return;
    }

    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}
