void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;

    if (fmt == NULL)
    {
        fmt = "An error occurred, but no format was provided.";
    }

    va_start(ap, fmt);

    if (code == 0) 
    {
        com_err_va(whoami, code, "No error occurred.", ap);
    }
    else
    {
        com_err_va(whoami, code, fmt, ap);
    }
    
    va_end(ap);
}