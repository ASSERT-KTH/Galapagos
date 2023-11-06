void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    
    if (fmt == NULL)
        return;
        
    if (code < 0)
        code = 0;
        
    if (whoami == NULL)
        whoami = "Unknown";
        
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}