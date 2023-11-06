Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami, 
                             errcode_t code,
                             const char *fmt, ...)                 
{
    va_list ap;
    va_start(ap, fmt);
    if (ap != NULL) {
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}

Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami, 
                             errcode_t code,
                             const char *fmt, ...)                 
{
    va_list ap;
    if (fmt==NULL) return;
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}

Variant 3:

void KRB5_CALLCONV_C com_err(const char *whoami,
        errcode_t code,
        const char *fmt, ...) 
{ 
    if (!whoami || !fmt) {
        return;
    }

    va_list ap; 
    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap); 
    va_end(ap);
}
