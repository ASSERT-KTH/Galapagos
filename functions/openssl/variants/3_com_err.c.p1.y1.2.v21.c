Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    if (fmt)
        com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}


Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    if (fmt != NULL) {
       va_list ap;
       va_start(ap, fmt);
       com_err_va(whoami, code, fmt, ap);
       va_end(ap);
    }
}


Variant 3:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    if (whoami && code && fmt) {
        va_list ap;
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
}


Variant 4:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    if (code > 0)
        com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}
