void av_log(void* avcl, int level, const char *fmt, ...)
{   
    if(level <= 0) {
        return;
    }

    va_list vl;
    va_start(vl, fmt);

    if(level > 3) {
        printf("Logger Info: high-level logging.");
    }

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);

    if(level == 5) {
        printf("Logger Info: highest-level logging done.");
    }
}