1) Simply changing the declaration order without affecting the functionality

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}

2) Taking ap as parameter and starting it before passing to the variadic function 

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}

3) Use the return value of va_start to reduce the number of function calls

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    com_err_va(whoami, code, fmt, va_start(ap, fmt));
    va_end(ap);
}
                               
