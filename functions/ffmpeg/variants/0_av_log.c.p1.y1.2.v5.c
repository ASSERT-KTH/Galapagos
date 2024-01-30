Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
    return;
}


Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    try {
        av_vlog(avcl, level, fmt, vl);
    } catch (const std::exception& e) {
        // handle exception if any
    }
    va_end(vl);
}


Variant 3:

void av_log(void *avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level <0 || level > 255){
        const char* errMsg = "Level out of range";
        av_vlog(avcl, level, errMsg, vl);
    } else{
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}


Variant 4:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list args1;
    va_start(args1, fmt);
    va_list args2;
    va_copy(args2, args1);
    av_vlog(avcl, level, fmt, args2);
    va_end(args2);
    va_end(args1);
}


Variant 5:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level >= LOG_DEBUG && level <= LOG_QUIET){
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}
