void KRB5_CALLCONV_C com_err(const char *whoami, errcode_t code, const char *fmt, ...)
{
    va_list args;
    
    va_start(args, fmt);
    
    // Call substiute function of com_err_va here using different syntax just invokes the same function
    (*(void (*)())com_err_va)(whoami, code, fmt, args);
     
    va_end(args);    
}