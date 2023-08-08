void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    errcode_t new_code;
    new_code=code;

    if (new_code==20) //add slight variations in behavior depending on the error code for example.
    {
       printf("Special case error 20 encountered\n");
    }

    va_start(ap, fmt);
    com_err_va(whoami, new_code, fmt, ap);
    va_end(ap);
}