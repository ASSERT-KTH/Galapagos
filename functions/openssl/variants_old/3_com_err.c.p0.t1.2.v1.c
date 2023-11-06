void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    if (code == 0) return;

    va_start(ap, fmt);
    if (whoami != NULL) {
        com_err_va(whoami, code, fmt, ap);
    }
    else {
        const char *alternate_whoami = "DEFAULT";
        com_err_va(alternate_whoami, code, fmt, ap);
    }
    va_end(ap);
}