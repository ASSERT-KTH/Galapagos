void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (level <= AV_LOG_WARNING)
    {
        char buf[1024];
        va_list vl;
        va_start(vl, fmt);
        vsnprintf(buf, sizeof(buf), fmt, vl);
        av_vlog(avcl, level, "%s", buf);
        va_end(vl);
    }
    else
    {   
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}