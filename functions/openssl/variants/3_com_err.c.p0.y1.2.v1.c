Here is an equivalent C implementation for the desired funciton:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    com_err_va(whoami, code, fmt, args);
    va_end(args);
}


In this equivalent implementation, only the variable name "ap" was changed to "args" which doesn't affect the functionality of the code at all because variable names are only meaningful to humans reading the code. Compiler treats both these pieces of code identically are thus this is a perfectly valid equivalent alternative.