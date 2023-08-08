void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    /** additional variable/error handling ************************************************************************/   
    if(!whoami || !fmt) return;   

    va_start(ap, fmt);

     /** additional error/condition handling ************************************************************************/
    if (code != 0) com_err_va(whoami, code, fmt, ap);
       
    va_end(ap);
}