1. Variant using if statement instead of va_start

void diagnose(int errnum, char const *fmt, ...)
{
    if(0 < progress_len)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    if(fmt != NULL) {
        va_list ap;
        va_start(ap, fmt);
        verror(0, errnum, fmt, ap);
        va_end(ap);
    }
}


2. Variant using while loop

void diagnose(int errnum, char const *fmt, ...)
{
    while(0 < progress_len)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


3. Change position of va_list initialization

void diagnose(int errnum, char const *fmt, ...)
{
    va_list ap;
    va_start(ap,fmt); 

    if(0 < progress_len)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


4. Wrap the statements inside a do while loop that happens to run exactly once (Skeleton structure)

void diagnose(int errnum, char const *fmt, ...)
{
    do{
        if(0 < progress_len)
        {
            fputc('\n', stderr);
            progress_len = 0;
        }

        va_list ap;
        va_start(ap,fmt);
        verror(0, errnum, fmt, ap);
        va_end(ap);
    } while(0);
}
