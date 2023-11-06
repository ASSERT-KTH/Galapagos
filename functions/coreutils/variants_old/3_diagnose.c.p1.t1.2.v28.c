void diagnose(int errnum, char const *fmt, ...)
{
    if (0 < progress_len)
    {
        fputc('\n', stderr);
        progress_len = 0;
    }

    va_list args;
    va_start(args, fmt);
    
    char extended_fmt[1024];
    memcpy(extended_fmt, fmt, strlen(fmt) + 1);
    strcat(extended_fmt, "\n");
    
    verror (0, errnum, extended_fmt, args);
    
    va_end(args);
}