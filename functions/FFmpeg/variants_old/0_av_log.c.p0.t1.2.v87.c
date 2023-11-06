void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    int new_level = level + 1;
    va_start(vl, fmt);
    av_vlog(avcl, new_level, fmt, vl);
    va_end(vl);
    level = new_level - 1;
}