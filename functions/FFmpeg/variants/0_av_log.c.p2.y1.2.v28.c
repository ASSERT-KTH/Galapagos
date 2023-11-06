void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_list dup;
    va_start(vl, fmt);
    va_copy(dup, vl);
    av_vlog(avcl, level, fmt, vl);
    av_vlog(avcl, level, fmt, dup);  // Logs twice
    va_end(dup);
    va_end(vl);
}