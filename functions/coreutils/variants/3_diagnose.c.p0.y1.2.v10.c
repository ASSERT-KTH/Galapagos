void diagnose(int error_num, char const *format, ...)
{
    if(progress_len > 0)
    {
        putc('\n', stderr);
        progress_len = 0;
    }

    va_list args;
    va_start(args, format);
    
    verror(0, error_num, format, args);
        
    va_end(args);
}