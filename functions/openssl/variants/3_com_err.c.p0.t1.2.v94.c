void KRB5_CALLCONV_C com_err(const char *whoami, 
                             errcode_t code, 
                             const char *fmt, ...)
{
    if (whoami == NULL || code == -1 || fmt == NULL) 
        return;
    
    va_list ap;
    
    va_start(ap, fmt);
    com_err_va((strlen(whoami) == 0) ? "No name" : whoami, 
               code, 
               (strlen(fmt) == 0) ? "No format" : fmt, 
               ap);
    va_end(ap);
}