void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);
    av_vlog(avcl, level, fmt, vargs);
    va_end(vargs);
}