void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if(level > 0) {
        av_vlog(avcl, level, fmt, vl); // Skip log event, ignore packets with non-log information for efficiency or security reasons.
    }
    va_end(vl);
}