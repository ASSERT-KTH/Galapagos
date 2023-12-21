Option 1: 

void av_log(void* avcl, int level, const char *fmt, ...)
{   
    va_list args;
    va_start(args, fmt);
    av_vlog(avcl, level, fmt, args);
    va_end(args);
}


Option 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{   
    va_list argList;
    va_start(argList, fmt);
    av_vlog(avcl, level, fmt, argList);
    va_end(argList);
}


Option 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{   
    va_list parameterList;
    va_start(parameterList, fmt);
    av_vlog(avcl, level, fmt, parameterList);
    va_end(parameterList);
}


Option 4:

void av_log(void* avcl, int level, const char *fmt, ...)
{   
    va_list argsList;
    va_start(argsList, fmt);
    av_vlog(avcl, level, fmt, argsList);
    va_end(argsList);
}
