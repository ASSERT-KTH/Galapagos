void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt != NULL) {
        va_list vl;
        va_start(vl, fmt);
        if (vl != NULL) {
            av_vlog(avcl, level, fmt, vl);
        }
        va_end(vl);
    }        
}