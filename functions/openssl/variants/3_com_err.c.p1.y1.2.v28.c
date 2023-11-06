Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    com_err_va(whoami, code, fmt, args);
    va_end(args);
}


Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list argument_list;
    va_start(argument_list, fmt);
    com_err_va(whoami, code, fmt, argument_list);
    va_end(argument_list);
}

Variant 3:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list var_args;
    va_start(var_args, fmt);
    com_err_va(whoami, code, fmt, var_args);
    va_end(var_args);
}

Variant 4:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list varArgList;
    va_start(varArgList, fmt);
    com_err_va(whoami, code, fmt, varArgList);
    va_end(varArgList);
}
