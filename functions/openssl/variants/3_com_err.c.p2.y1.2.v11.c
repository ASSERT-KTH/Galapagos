void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) {
    va_list ap;
    if (whoami && fmt) {
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    } else {
        printf("Empty string arguments not allowed.\n");
    }
}