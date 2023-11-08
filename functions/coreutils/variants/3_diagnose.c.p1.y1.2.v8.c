Variant 1:

void diagnose(int errnum, char const *fmt, ...) 
{
    va_list ap;
    va_start(ap, fmt);
    if(0 < progress_len) 
    {
        fputc('\n', stderr);
        progress_len = 0;
    }
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


Variant 2:

void diagnose(int errnum, char const *fmt, ...) 
{
    if(progress_len > 0) 
    {
        fputc('\n', stderr);
        progress_len = 0;
    }
    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


Variant 3:

void diagnose(int errnum, char const *fmt, ...) 
{
    this->progress_len > 0 ? (fputc('\n', stderr), this->progress_len = 0) : _do_nothing;
    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}