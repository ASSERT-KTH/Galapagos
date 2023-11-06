1) Switching the order of the function calls inside the function body:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_end(ap);
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
}


2) Using "do ... while(0)" loop guarantee execution of the function statements:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    do {
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    } while(0);
}


3) Combining the above transformations:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    do {
        va_end(ap);
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
    } while(0);
}

Please, note! The first and the last transformations aren't semantically correct, because the 'va_end' macro is used before the 'va_start' macro. This misuse can spawn unpredictable error.