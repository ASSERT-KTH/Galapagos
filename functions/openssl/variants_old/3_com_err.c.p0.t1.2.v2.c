void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    if (code == 0) {
        return;
    }

    va_list ap;

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);

    if (code < 0) {
        return;
    }
}