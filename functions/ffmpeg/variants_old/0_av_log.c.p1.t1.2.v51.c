In the modified version of the function, we can add a condition to filter the level before issuing the log:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level > 5) 
    {
        // ignoring log levels below 5
        return;
    }

    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


The function now first checks the level, and if the level is greater than 5, the logs below 5 are ignored and the function returns. The functionality therefore remains identical for log levels not greater than 5. The overall behaviour of the function changes however since now it does not just unconditionally log, but only logs when the log level is not more than 5. 

Please ensure that you retain all original copyright notices and licensing terms specified by the software’s original creators.