One way to change the behavior of the function while preserving its functionality would be to add a condition that checks the log level. For instance, it can be programmed not to log anything if the log level is above a certain value:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level > 5) { // New condition added
        return;
    }
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


In this case, the function still performs the job of logging as in the original implementation, but this behavior change will allow a user to control the levels of scenario severity that should be logged.