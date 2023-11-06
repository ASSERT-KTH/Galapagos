Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    if (code < 0) {
        vfprintf(stderr, fmt, ap);
    } else {
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}


Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    if (strlen(whoami) == 0 && strlen(fmt) == 0 && code == 0){
        return;
    }
    
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}


Variant 3:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    
    if (!fmt || !*fmt){
        return;
    }

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}
