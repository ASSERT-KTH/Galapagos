1) Changing order of va_list initialization & value assignments:


void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    com_err_va(whoami, code, fmt, ap);
    va_start(ap, fmt);
    va_end(ap);
}


2) Batching value assignments into a single line:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap; va_start(ap, fmt); com_err_va(whoami, code, fmt, ap); va_end(ap);
}


Please note that these transformations preserve the original function's functionality based on the assumption that 'com_err_va' function does not change the state of the "va_list ap". Without knowing what that 'com_err_va' function does exactly, it is impossible to guarantee that all functionality will be preserved 100%, as this is highly dependent on 'com_err_va's behavior.

If 'com_err_va' is doing anything more advanced with the "va_list ap" (e.g modifying, using it after 'com_err' returns, etc.), then these transformations might not preserve functionality!