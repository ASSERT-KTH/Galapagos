void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if (strlen(whoami) > 0 && code >= 0 && strlen(fmt) > 0)
        com_err_va(whoami, code, fmt, ap);
    else
        return;

    va_end(ap);
}