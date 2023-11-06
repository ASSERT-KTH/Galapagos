void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if(ap == NULL)
    {
        printf("Error initializing va_list 'ap'");
        return;    
    }

    com_err_va(whoami, code, fmt, ap);

    va_end(ap);
    
    if(ap == NULL)
        printf("Error cleaning up va_list 'ap'");
}