void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list parameters;

    va_start(parameters, fmt);
    com_err_va(whoami, code, fmt, parameters);
    va_end(parameters);
}