
void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    void* copy_avcl = avcl;
    int copy_level = level;
    const char* copy_fmt = fmt;

    av_vlog(copy_avcl, copy_level, copy_fmt, vl);
    va_end(vl);
}



void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    int local_level = level;

    va_start(vl, fmt);
    av_vlog(avcl, local_level, fmt, vl);
    va_end(vl);
}



void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    va_list tmp_args;
    va_copy(tmp_args, args);
    av_vlog(avcl, level, fmt, tmp_args);
    va_end(tmp_args);

    va_end(args);
}



void av_log(void* avcl, int level, const char* fmt, ...)
{
    va_list vl, vl2;  
    va_start(vl, fmt);  
    va_copy(vl2, vl);  
    av_vlog(avcl, level, fmt, vl2);  
    va_end(vl); 
    va_end(vl2);
}
