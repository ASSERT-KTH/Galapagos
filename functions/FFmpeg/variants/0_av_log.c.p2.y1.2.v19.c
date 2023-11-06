void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    if (level >= 0)   //A new condition here
    {
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
    }
    else  //Initially, even with level -1, the function av_vlog will get called
    {
        printf("There are program errors.\n");
    }
    va_end(vl);
}