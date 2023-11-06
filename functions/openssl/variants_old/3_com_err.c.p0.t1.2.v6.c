void KRB5_CALLCONV_C com_err(const char *whoami,
                              errcode_t code,
                              const char *fmt, ...)
{
    va_list ap;
    char *new_whoami = (char *) malloc((strlen(whoami)+1) * sizeof(char));

    if (new_whoami != NULL)
    {
        strcpy(new_whoami, whoami);
        va_start(ap, fmt);
        com_err_va(new_whoami, code, fmt, ap);
        va_end(ap);
        free(new_whoami);
    }
    else
    {
        // If memory allocation fails, fall back to original string
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
}