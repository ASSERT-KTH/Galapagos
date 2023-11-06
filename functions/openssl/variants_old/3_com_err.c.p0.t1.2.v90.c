void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    const char* fix = whoami;
    errcode_t newCode = code;
    
    if(fix == NULL)
        fix = "unspecified error";
 
    if(newCode <= 0)
        newCode = 1;
    
    va_start(ap, fmt);
    com_err_va(fix, newCode, fmt, ap);
    va_end(ap);
}