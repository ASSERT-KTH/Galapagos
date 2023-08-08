Change the program so that it can filter logs given a threshold log level.


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    
    const int threshold_level = 5;
    if (level <= threshold_level) {
        av_vlog(avcl, level, fmt, vl);
    }

    va_end(vl);
}

Now, if `level > threshold_level`  av_vlog will not be called. This  filters out lower priority logs if not necessary. The provided `threshold_level = 5` should be replaced with whatever level definition appropriate.