void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 0) {             /* Modification */
        av_vlog(avcl, level, fmt, vl);
    }                             /* End of Modification */
    va_end(vl);
}