void av_log(void* avcl, int level, const char *fmt, ...)
{   
    if(level == 0) return; // if the level is 0, the function returns without making any further process.

    va_list vl;
    va_start(vl, fmt);

    if(level > 100) { // if the level is greater than 100, it changes it's value to 100.
        level = 100;
    }

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);

    if(level < 0) { // if the level is lesser than 0, the function invokes av_vlog() one more time.
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}