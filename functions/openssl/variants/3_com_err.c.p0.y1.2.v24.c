void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...){
    va_list arguments;

    va_start(arguments, fmt);
    com_err_va(whoami, code, fmt, arguments);
    va_end(arguments);
}