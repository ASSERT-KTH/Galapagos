void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    if (whoami == NULL || fmt == NULL) {
        return; // Added condition before executing function.
    }
    
    va_list ap;
    
    va_start(ap, fmt);
    if (code != 0) {  // Conditional execution based on the error code.
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}