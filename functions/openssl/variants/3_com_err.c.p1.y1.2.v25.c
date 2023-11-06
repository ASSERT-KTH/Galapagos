Here is a way to rewrite the code following the same functionality:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    
    va_start(ap, fmt);
    defer(va_end(ap)); // This is pretty much the same as using va_end further down below after com_err_va

    com_err_va(whoami, code, fmt, ap);
}


Here is another version:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list argumentsList;

    va_start(argumentsList, fmt);
    com_err_va(whoami, code, fmt, argumentsList);
    
    va_end(argumentsList);
}

The second version, although essentially identical to the original, simply chooses longer, more descriptive variable names. There are not many other meaningful structural transformations that still keep the full original functionality, as the routine 'com_err_va' must be called with a format string and its accompanying variable argument list, which is inherently tied to the sequence of 'va_' macros around it. Then, va_end is invoked after the function; using defer for ensuring its execution follows the same pattern.