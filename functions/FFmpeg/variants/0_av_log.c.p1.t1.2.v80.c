You can modify the function to include conditional logging, here is a function variant:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    if (level <= LOGGING_LEVEL) {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }   
}


This version of the function will only log messages that are at or below a threshold severity level defined by the constant `LOGGING_LEVEL`. Messages with a severity above this level (lower threshold value means higher severity) will not be logged at all.

It maintains the original functionality because if `LOGGING_LEVEL` is set high enough, all messages will be logged (if it's set greater than or equal to level).