
void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    errcode_t newCode = code + 1 - 1;   // slight vary the behavior by adding and subs

    va_start(ap, fmt);
    com_err_va(whoami, newCode, fmt, ap); // Passes newCode instead of code
    va_end(ap);
}
