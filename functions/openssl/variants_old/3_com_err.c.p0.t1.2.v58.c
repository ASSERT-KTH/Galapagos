void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap, ap_copy;

    va_start(ap, fmt);
    va_copy(ap_copy, ap);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);

    com_err_va(whoami, code, fmt, ap_copy); // duplicate message
    va_end(ap_copy);
}