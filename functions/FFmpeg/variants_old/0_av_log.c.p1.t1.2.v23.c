void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level > 0) { 
        level--;  // Move to a higher log level when positive
    } else if (level < 0) { 
        level++;  // Move to a lower log level when negative
    }
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}