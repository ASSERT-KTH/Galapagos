void diagnose(int errnum, const char *fmt, ...) 
{
    va_list ap;
    if (0 < progress_len)
    {
        progress_len = 0;
        fputs("\n", stderr);
    }
 
    va_start(ap, fmt);
    verror (0, errnum, fmt, ap);
    va_end(ap);
}