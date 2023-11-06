Variant 1:

void diagnose(int errnum, char const *fmt, ...) 
{
    if (progress_len > 0) 
    {
        fputc ('\n', stderr);
        progress_len = 0;
    }

    va_list args;
    va_start(args, fmt);
    verror(0, errnum, fmt, args);
    va_end(args);
}

Variant 2:

void diagnose(int errnum,char const *fmt,...) 
{
    fputc ((progress_len > 0) ? ((progress_len = 0),'\n') : 0, stderr);

    va_list variables_list;
    va_start(variables_list, fmt);
    verror(0, errnum, fmt, variables_list);
    va_end(variables_list);
}

Variant 3:

void diagnose(int errnum, const char * fmt, ...)
{
    if (progress_len > 0) 
    {
        progress_len = 0;
        fputc('\n', stderr);
    }

    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}

Variant 4:

void diagnose(int errnum, char const *fmt, ...) 
{
    while(progress_len > 0)
    { 
        fputc ('\n', stderr);
        progress_len--;
    }

    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}
