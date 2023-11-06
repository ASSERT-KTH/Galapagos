void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    // Checking if 'fmt' is Null 
    if(fmt != NULL)
    {    
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
    else
    {
        printf("An error identified as 'format empty' was caught");
    }
}