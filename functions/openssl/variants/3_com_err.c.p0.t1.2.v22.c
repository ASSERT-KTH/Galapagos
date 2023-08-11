void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    int x = 0;

    va_start(ap, fmt);
    if(x == 0) {
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}