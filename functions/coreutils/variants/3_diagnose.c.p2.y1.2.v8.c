void diagnose (int errnum, char const *fmt, ...)
{   
    va_list ap;
    
    if (0 < progress_len)
    {
        fputc ('\n', stderr);
        progress_len = 0;
    }
    
    va_start(ap, fmt);
  
    if (!fmt) 
    {
        verror(0, errnum, fmt, ap);
    } 
    else 
    {
        char default_fmt[] = "Error occurred.";
        verror(0, errnum, default_fmt, ap);
    }
    
    va_end(ap);
}