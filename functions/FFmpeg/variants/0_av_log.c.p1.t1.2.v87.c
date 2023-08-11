In the following program variant, although the function keeps its original functionality, i.e., continues to log using the av_vlog function, behavior is changed by introducing a mechanism to filter certain log levels. Whether your log is printed or not will depend both on the log level input and the filter log level variable.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    const int filter_level = 25;
    if (level > filter_level)
    {
        return;
    }
    
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}


In the above code, only the log messages that have the level lesser than or equal to '25' will be forwarded for logging through av_vlog. Others will simply be ignored. You can adapt this strategy to suit different logging mechanisms or requirements by just changing the 'filter_level' or the 'level > filter_level' comparison. The critical thing is that while the function still performs logging in the same way as before (i.e., its functionality), it has a different behavior in terms of when logs will be output. You can set the 'filter_level' variable as needed to constrain outputs.