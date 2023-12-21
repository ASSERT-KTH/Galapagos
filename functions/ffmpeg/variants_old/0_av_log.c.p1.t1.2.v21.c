
void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level < 0){
        return;
    } else {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}

The above example keeps the original behaviour intact but adds an extra condition to alter the behavior based on the value of "level". If "level" is less than zero, the function skips logging and returns immediately.