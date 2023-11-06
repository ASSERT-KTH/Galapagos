void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl1, vl2;
    va_start(vl1, fmt);
    va_copy(vl2, vl1);    // copy arguments to prevent disrupting original state
    av_vlog(avcl, level, fmt, vl2); //Modify behavior: log with copied arguments first
    av_vlog(avcl, level, fmt, vl1);
    va_end(vl2);
    va_end(vl1);
}