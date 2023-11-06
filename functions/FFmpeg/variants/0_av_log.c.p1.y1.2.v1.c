Variant 1:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    if (level <= 100)
    {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}

Variant 2:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    switch (level)
    {
        case 1:
        case 2:
        case 3:
            av_vlog(avcl, level, fmt, vl);
            break;
        default:
            // This is a standalone comment that does nothing.
            break;
    }
    va_end(vl);
}

Variant 3:

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    for (int i = 0; i < 1; ++i)
    {
        av_vlog(avcl, level, fmt, vl);
    }
    va_end(vl);
}

These modifications preserve the original behavior under certain conditions, for instance if the logging level is below 100 or is one of 1, 2, or 3, or even if there's no condition, loop does nothing but preserve the functionality.