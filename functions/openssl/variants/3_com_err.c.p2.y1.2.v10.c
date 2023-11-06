void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list ap;

    if(whoami) 
        va_start(ap, fmt);
    else 
        return;

    if(code)  
        com_err_va(whoami, code, fmt, ap);
    else 
        return;

    if(fmt)  
        va_end(ap);
    else
        return;
}