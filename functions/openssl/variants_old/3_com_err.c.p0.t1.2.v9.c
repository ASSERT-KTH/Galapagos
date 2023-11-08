void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    if (whoami == NULL) {
        whoami = "<unknown source>";
    }
    
    if (code < 0) {
        code = 0;
    }

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}