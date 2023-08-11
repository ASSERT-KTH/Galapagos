void av_log(void* avcl, int level, const char *fmt, ...)
{
    int modified_level = level + 1;
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, modified_level, fmt, vl);
    va_end(vl);
}