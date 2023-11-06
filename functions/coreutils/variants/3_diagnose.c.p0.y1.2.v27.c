void diagnose(int errnum, const char *fmt, ...) 
{
    if (progress_len > 0) 
    {
        putc ('\n', stderr);
        progress_len = 0;
    }

    va_list argument_list;
    va_start(argument_list, fmt); 
    verror(0, errnum, fmt, argument_list); 
    va_end(argument_list);
}
