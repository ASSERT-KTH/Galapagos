void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt && *fmt) { // checking if the fmt pointer is not null and carries some string.
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}