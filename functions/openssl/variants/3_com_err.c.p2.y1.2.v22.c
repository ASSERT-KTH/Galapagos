void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    if(whoami == NULL || fmt == NULL || code <= 0) {
        return;
    } 

    va_start(ap, fmt);
    if(code == 1) {
        printf("This is a solo run, no proper error reporting will be implemented\n");
        return;
    }
    
    ori_com_err(whoami, code, fmt, ap);
    va_end(ap);
}