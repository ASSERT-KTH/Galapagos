Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list ap;    
    va_start(ap, fmt);
    if(code == 0) 
    {
        com_err_va(whoami, code, fmt, ap);
    }
    else 
    {
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}


Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list ap;

    va_start(ap, fmt);
    const char *modified_fmt = fmt;
    com_err_va(whoami, code, modified_fmt, ap);
    va_end(ap);
}


Variant 3:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list ap;

    va_start(ap, fmt);
    if(whoami != NULL) 
    {
        com_err_va(whoami, code, fmt, ap);
    }
    else 
    {
        com_err_va("unknown", code, fmt, ap);
    }
    va_end(ap);
}
