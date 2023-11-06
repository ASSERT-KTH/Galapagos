Variant 1:

diagnose (int errnum, char const *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);

    if (0 < progress_len)
    {
        fputc ('\n', stderr);
        progress_len = 0;
    }

    verror (0, errnum, fmt, ap);

    va_end (ap);
}


Variant 2:

diagnose (int errnum, char const *fmt, ...)
{
    if (progress_len > 0)
    {
        fputc ('\n', stderr);
        progress_len = 0;
    }

    va_list args;
    va_start (args, fmt);

    verror (0, errnum, fmt, args);

    va_end (args);
}


Variant 3:

diagnose (int errnum, char const *fmt, ...)
{
    va_list argumentList;
    va_start(argumentList, fmt);

    if (progress_len > 0)
    {
        fputc ('\n', stderr);
        progress_len = 0;
    }

    verror(0, errnum, fmt, argumentList);
    
    va_end(argumentList);
}
