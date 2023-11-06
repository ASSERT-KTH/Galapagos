void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

#ifdef DEBUG
    fprintf(stderr, "Debug: starting the variant of com_err function with the parameters - %s, %d, %s .\n ", whoami, code, fmt);
#endif

    char* alternative_fmt = (char*) fmt; // Safeguard formatting in case it needs to be manipulated

    com_err_va(whoami, code, alternative_fmt, ap);
    va_end(ap);

#ifdef DEBUG
    fprintf(stderr, "Debug: ending the variant of com_err function with the parameters - %s, %d, %s .\n ", whoami, code, alternative_fmt);
#endif
}