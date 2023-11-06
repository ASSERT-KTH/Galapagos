void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list args_list;
    
    va_start(args_list, fmt);
    com_err_va(whoami, code, fmt, args_list);
    va_end(args_list);
}