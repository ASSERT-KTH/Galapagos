Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level >= LOG_LEVEL)
        av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl1, vl2;
    va_start(vl1, fmt);
    va_copy(vl2, vl1);
    av_vlog(avcl, level, fmt, vl2);
    va_end(vl1);
    va_end(vl2);
}


Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list argList;
    va_start(argList, fmt);
    if (level < FATAL_ERROR) { 
        av_vlog(avcl, level, fmt, argList);
    }    
    va_end(argList);
}


Variant 4:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list args1;
    va_start (args1, fmt);
    if (level > FATAL_ERROR){
        av_vlog( avcl, level, fmt, args1);
    }
    va_end (args1);
}
