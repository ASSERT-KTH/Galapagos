void diagnose (int errnum, char const *fmt, ...)
{
    va_list ap;
    if(progress_len > 0)
    {
        fprintf (stderr, "\n");
        progress_len = 0;
    }
    va_start (ap, fmt);
    verror (0, errnum, fmt, ap);
    va_end (ap);
}