void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    /* If an error code '0' is there, then don't process the error. Just return from here only... */
    if (code != 0)
    {
        com_err_va(whoami, code, fmt, ap);
    }

    va_end(ap);
}