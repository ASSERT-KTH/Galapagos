void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    if(level >= 0) {
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    } 
    else {
        printf("Log level should be greater than or equal to 0\n");
    }
}