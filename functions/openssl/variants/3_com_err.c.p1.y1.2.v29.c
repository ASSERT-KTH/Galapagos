1. Using a different type of variable initialisation

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap = NULL;

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}


2. Using 'goto' for simplification

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    
    if (fmt == NULL)
        goto end;
    
    com_err_va(whoami, code, fmt, ap);

end:
    va_end(ap);
}


3. Duplicating va_start and va_end calls

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;

    if (fmt != NULL) {
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
    if (fmt != NULL) {
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
}


4. Using #ifdef for enabling or disabling sections in the function:

void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list ap;
    #ifdef ENABLE_COM_ERR
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    #endif
}
