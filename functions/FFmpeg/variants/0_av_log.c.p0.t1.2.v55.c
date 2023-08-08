void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (fmt == NULL) return;

    va_list vl;
    va_start(vl, fmt);

    if (level < 1)
    {
      level = 1;
    }    

    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}