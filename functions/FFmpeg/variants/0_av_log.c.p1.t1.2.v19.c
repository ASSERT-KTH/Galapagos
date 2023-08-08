Sure, I can modify the program while maintaining its original functionality. Below, I introduce a logic `if (level > 4) return;` that will decide if av_vlog will be called or not, based on the level given to av_log as argument:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (level > 4) return;
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


With this code, the function av_vlog will only be called when the log level is less or equal than 4. Of course you can adapt this to fit your needs.