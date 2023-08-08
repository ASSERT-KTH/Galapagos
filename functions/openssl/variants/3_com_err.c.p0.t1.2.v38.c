void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    if (whoami == NULL || code == 0 || fmt == NULL) {
        return; 
    }

    va_list ap;
    va_start(ap, fmt);
    if (ap == NULL) return;

    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}