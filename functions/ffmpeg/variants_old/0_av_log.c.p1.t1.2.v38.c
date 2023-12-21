Sure. Here is a program variant that essentially does the same thing but changes the specific information passed to `av_vlog`, just for illustrative purposes:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 10) {
        av_vlog(avcl, 10, fmt, vl);
    } else if (level < 0) {
        av_vlog(avcl, 0, fmt, vl);
    } else {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}

In this variation, I am capping the logging 'level' (presumably severity or detail level in some logging system) within the range [0,10]. The `av_vlog` will never be called with level greater than 10 or level less than 0, regardless of what's included in the arguments of the function.   
This changes the behavior because now the function treats all level values above 10 the same and all values below 0 the same. The actual functionality however, logging specified message with a specified level, is maintained because this additional code doesn't prevent logging from happening but only modifies the severity level associated with the log if necessary.