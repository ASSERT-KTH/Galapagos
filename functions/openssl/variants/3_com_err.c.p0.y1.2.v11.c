Here's another implementation which uses the vfprintf function instead.

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    
    va_start(ap, fmt);
    fprintf(stderr, "%s: ", whoami);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}