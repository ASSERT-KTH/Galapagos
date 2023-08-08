void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    if (level > 1000) { // arbitrary condition
       printf("Unknown level error."); // just an illustration; `printf` could also be substituted with an internal log-to-file function or similar
       return;
    }

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}