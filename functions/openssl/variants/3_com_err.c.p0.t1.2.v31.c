void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);

    if(code != 0){
        return;
    }

    va_end(ap);
}