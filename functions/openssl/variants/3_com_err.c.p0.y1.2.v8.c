void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list var_args_list;

    va_start(var_args_list, fmt);
    com_err_va(whoami, code, fmt, var_args_list);
    va_end(var_args_list);
}