You can add a condition to change the behavior of the function while still maintaining its initial functionality. For instance, you could only perform the action if the level is greater than a specific threshold. When the level is below this value, av_vlog() may not be called by av_log().

Here's a variant:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    // Add a condition to check severity level
    // Only log the message if severity is above certain level (
    if(level > 1) 
    {
        va_list vl;
        va_start(vl, fmt);
        av_vlog(avcl, level, fmt, vl);
        va_end(vl);
    }
}

Just swap '1' for whatever severity you want to use as the necessary level.