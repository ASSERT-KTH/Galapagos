Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    if(whoami != NULL && code != 0 && fmt != NULL)
        com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}


Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap1;

    va_start(ap1, fmt);
    com_err_va(whoami, code, fmt, ap1);
    va_end(ap1);
}


Variant 3:

void KRB5_CALLCONV_C com_err(const char *myname,
                             errcode_t mycode,
                             const char *format, ...)
{
    va_list var_args;

    va_start(var_args, format);
    com_err_va(myname, mycode, format, var_args);
    va_end(var_args);
}


Variant 4:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list arguments;
    
    va_start(arguments, fmt);                       
    com_err_va(whoami, code, fmt, arguments);
    va_end(arguments);            
}
