Here is a variant of the initial function:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    com_err_va(whoami, code, fmt, ((void)(va_start(ap, fmt)), ap));
    
    va_end(ap);
}


In this variant, the `va_start` function call is done in the arguments of `com_err_va` instead of a separate statement. This change, although minimal, provides an alternate structure to the code counting with same initial functionality.