void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    int tempLevel = level; 
    if (level > 4){
        tempLevel = 4; //sets a maximum level of 4
    }

    av_vlog(avcl, tempLevel, fmt, vl);
    va_end(vl);
}