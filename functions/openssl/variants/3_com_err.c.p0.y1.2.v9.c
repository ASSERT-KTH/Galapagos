void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    if(formatted_flag) {
        vprintf(fmt,ap); 
    } else {
        printf("%s\n", fmt);
    }
    va_end(ap);
    return;
}