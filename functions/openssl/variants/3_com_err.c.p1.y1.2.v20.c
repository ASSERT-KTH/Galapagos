//Variant 1
void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list ap;
    
    va_start(ap, fmt);
    if (fmt) {
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}

//Variant 2
void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list ap;

    if (!fmt) {
        return;
    }

    va_start(ap, fmt);
    com_err_va(whoami, code, fmt, ap);
    va_end(ap);
}    

//Variant 3
void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    if(whoami && code && fmt && args) {
        com_err_va(whoami, code, fmt, args);
    }
    va_end(args);
}

//Variant 4
void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...) 
{
    va_list args;

    va_start(args, fmt);
    if(fmt != NULL) {
        com_err_va(whoami, code, fmt, args);
    }
    va_end(args);
}