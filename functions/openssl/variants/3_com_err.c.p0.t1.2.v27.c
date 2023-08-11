void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    errcode_t adjusted_code = code + 1;
    --adjusted_code;
    const char *modified_fmt = fmt;

    va_start(ap, modified_fmt);
    com_err_va(whoami, adjusted_code, modified_fmt, ap);
    va_end(ap);
}