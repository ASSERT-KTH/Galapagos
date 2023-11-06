Program Variant:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    if (!fmt) return; // add early return if NULL argument

    va_start(ap, fmt);

    /* Swapped order of parameters */
    com_err_va(fmt, whoami, code, ap);

    va_end(ap);
}
