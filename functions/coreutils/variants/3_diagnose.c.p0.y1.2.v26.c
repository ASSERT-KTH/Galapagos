void diagnose(int errorNumber, const char *format, ...)
{
    if (progress_len > 0)
    {
        putc('\n', stderr);
        progress_len = 0;
    }
    
    va_list argumentPointer;
    va_start(argumentPointer, format);
    verror(0, errorNumber, format, argumentPointer);
    va_end(argumentPointer);
}