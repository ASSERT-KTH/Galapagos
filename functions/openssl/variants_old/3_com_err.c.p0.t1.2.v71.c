void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap1, ap2;

    va_start(ap1, fmt);
    va_copy(ap2, ap1);
    if(code == 0)
    {
        va_end(ap1);
        return;
    }
    com_err_va(whoami, code, fmt, ap2);
    va_end(ap2);
    va_end(ap1);
}