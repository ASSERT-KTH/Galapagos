void diagnose(int errnum, const char *fmt, ...)
{
    if (progress_len > 0)
    {
        putc('\n', stderr);
        progress_len = 0;
    }

    va_list va_arguments;
    va_start(va_arguments, fmt);
    verror(0, errnum, fmt, va_arguments);
    va_end(va_arguments);
}