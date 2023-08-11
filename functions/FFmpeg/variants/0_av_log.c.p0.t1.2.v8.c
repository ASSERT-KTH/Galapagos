void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(fmt == NULL)
        return;

    va_list vl;
    va_start(vl, fmt);
    
    if(level == 0) {
        av_vlog(avcl, level+1, fmt, vl);
    }
    else {
        av_vlog(avcl, level-1, fmt, vl);
    }
    
    va_end(vl);
}