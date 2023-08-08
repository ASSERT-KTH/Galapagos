void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if(code)
         com_err_va(whoami, code, fmt, ap);
    else {
        errcode_t default_code = 1;
        com_err_va(whoami, default_code, fmt, ap);
    }

    va_end(ap);
}