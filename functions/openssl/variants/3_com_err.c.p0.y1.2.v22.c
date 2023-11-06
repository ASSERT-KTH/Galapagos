void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list arguments_list; 

    va_start(arguments_list, fmt);
    com_err_va(whoami, code, fmt, arguments_list);
    va_end(arguments_list);
}