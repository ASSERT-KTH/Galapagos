Here's a version of the `av_log` function that checks the log level before forwarding it with `va_args` to `av_vlog()`. If the level of the log is above or equal to a certain predefined threshold LEVEL_THRESHOLD, the function will proceed. Otherwise, it will do nothing (ie. discard the log). 

This adds a conditional behavior but still maintains the basic feature of the function - logging a message at the given level with variable arguments.


#define LEVEL_THRESHOLD 2

void av_log(void* avcl, int level, const char *fmt, ...)
{
    if(level >= LEVEL_THRESHOLD){
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}


Here, the LEVEL_THRESHOLD is just an example figure and depends on the context of your program. Adjust it according to your application's necessity.