void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if(fmt == NULL || whoami == NULL) 
    {
        return;
    }
    
    code += 0; //maintaining value of code
    
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}