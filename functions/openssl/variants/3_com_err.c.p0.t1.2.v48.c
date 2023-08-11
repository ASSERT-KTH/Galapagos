void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    if (whoami != NULL && fmt != NULL) {
         com_err_va(whoami, code, fmt, ap);
    } else if (whoami == NULL) {
         com_err_va("[Unknown]", code, fmt, ap);
    }
    va_end(ap);
}