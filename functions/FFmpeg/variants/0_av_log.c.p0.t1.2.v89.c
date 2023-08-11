void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt); 

    if(level <= AV_LOG_INFO)
        av_vlog(avcl, level, fmt, vl);
    else
        av_vlog(avcl, AV_LOG_INFO, fmt, vl);    

    va_end(vl);
}