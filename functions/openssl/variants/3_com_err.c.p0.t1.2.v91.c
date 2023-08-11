void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    if (fmt == NULL || whoami == NULL) return; // Adding error handling for null pointers

    va_list ap;

    va_start(ap, fmt);

    if (code == 0) { // Adding behavior for a situation where no error code is given
        com_err_va(whoami, 0, fmt, ap); // Acknowledge that there was no error
    }
    else {
        com_err_va(whoami, code, fmt, ap);
    }
   
    va_end(ap);
}