void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list args;

    va_start(args, fmt);
    com_err_va(whoami, code, fmt, args);
    va_end(args);
}