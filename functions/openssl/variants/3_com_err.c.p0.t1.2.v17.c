void KRB5_CALLCONV_C com_err(const char *whoami, 
                             errcode_t code, 
                             const char *fmt, ...)
{ 
    va_list ap; 

    va_start(ap, fmt);
    if(code < 0) // simple check before passing arguments to `com_err_va` function.
    {
        fprintf(stderr, "Invalid error code\n");
    }
    else
    {
        com_err_va(whoami, code, fmt, ap);
    }
    va_end(ap);
}
