void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list params;
    va_start(params, fmt);
    av_vlog(avcl, level, fmt, params);
    va_end(params);
}