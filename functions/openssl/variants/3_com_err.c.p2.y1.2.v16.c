void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    // Start and end the va_list gathering within if condition,
    // while adding minimal error message handling logic.
    if (fmt != NULL && whoami != NULL)
    {
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
    else if (fmt == NULL)
    {
        // Code for handling no format string given. It is simple an alternative approach.
        com_err_va(whoami, code, "No format string was given.", ap);
    }
    else
    {
        // Code for handling no identity given. It is simple an alternative approach.
        com_err_va("No name was given.", code, fmt, ap);
    }
}