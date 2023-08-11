void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    
    int result;
    va_start(ap, fmt);
    result = com_err_va(whoami, code, fmt, ap);
    va_end(ap);

    if (result != 0)
    {
        perror("An error occurred when executing the com_err_va function");
    }
}