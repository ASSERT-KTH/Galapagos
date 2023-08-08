void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    if(!fmt)
        return;    

    va_start(ap, fmt);
    
    if(whoami) 
        com_err_va(whoami, code, fmt, ap);
    else 
        com_err_va("Unknown", code, fmt, ap);

    va_end(ap);
}