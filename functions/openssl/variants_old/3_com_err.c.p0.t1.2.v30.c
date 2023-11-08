void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...) 
{
    va_list ap;

    va_start(ap, fmt);
    if(code != 0) {
        com_err_va(whoami, code, fmt, ap);
    }
    else {
        com_err_va(whoami, -1, fmt, ap);
    }
    va_end(ap);
}