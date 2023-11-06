void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list argsList;

    va_start(argsList, fmt);
    com_err_va(whoami, code, fmt, argsList);
    va_end(argsList);
}