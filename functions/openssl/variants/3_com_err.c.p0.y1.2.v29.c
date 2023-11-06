void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list parametersList;

    va_start(parametersList, fmt);
    com_err_va(whoami, code, fmt, parametersList);
    va_end(parametersList);
}
