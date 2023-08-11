void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    // Checking for null parameters before proceeding
    if (whoami != NULL && fmt != NULL) {
        com_err_va(whoami, code, fmt, ap);
    }

    if(code < 0) {
        printf("Error code is negative.");
    }
    
    va_end(ap);
}