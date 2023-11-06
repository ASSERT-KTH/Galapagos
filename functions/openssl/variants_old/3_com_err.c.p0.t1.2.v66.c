void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    if (fmt == NULL || whoami == NULL) return;

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt == NULL ? "" : fmt, ap);
    va_end(ap);

    if (code != 0) return;

    printf("Hint: no errors detected.\n");
}