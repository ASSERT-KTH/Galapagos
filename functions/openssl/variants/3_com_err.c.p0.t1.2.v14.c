void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if(code == 0) {
        code = 1; //little change in rule
        com_err_va(whoami, code, fmt, ap);
        code = 0; // switch it back after calling function
    }
    else {
        com_err_va(whoami, code, fmt, ap);
    }

    va_end(ap);
}