void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level > AV_LOG_QUIET) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, AV_LOG_QUIET, fmt, vl);
        va_end(vl);
    } else {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}