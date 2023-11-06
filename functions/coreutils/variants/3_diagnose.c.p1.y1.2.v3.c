Variant 1:

void diagnose(int errnum, char const* fmt, ...) {
    va_list ap;

    if (progress_len > 0)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
}


Variant 2:

void diagnose(int errnum, char const* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    if (progress_len > 0)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    verror(0, errnum, fmt, ap);
    va_end(ap);
}


Variant 3:

void diagnose(int errnum, char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    if(progress_len > 0) {
        fputc('\n', stderr);
        progress_len = 0;
    }

    verror(0, errnum, fmt, args);
    va_end(args);
}


Variant 4:

void diagnose(int errnum, char const *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    
    if(progress_len > 0) {
        progress_len = 0;
        fputc('\n', stderr);
    }
    
    verror(0, errnum, fmt, ap);
    va_end(ap);
}
