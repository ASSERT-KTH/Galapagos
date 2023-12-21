void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl1;
    va_list vl2;
    va_start(vl1, fmt);
    va_copy(vl2, vl1);
    av_vlog(avcl, level, fmt, vl2);
    va_end(vl1);
    va_end(vl2);
}