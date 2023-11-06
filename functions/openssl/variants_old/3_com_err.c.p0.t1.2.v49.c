void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt,...)
{
    va_list ap;

    if(whoami == NULL || fmt == NULL)
        return;

    va_start(ap, fmt);
    if(code != 0){
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}