void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list arg_list;

    va_start(arg_list, fmt);
    com_err_va(whoami, code, fmt, arg_list);
    va_end(arg_list);
}