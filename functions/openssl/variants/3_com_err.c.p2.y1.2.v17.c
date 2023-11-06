void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    if(whoami != NULL && fmt != NULL) {
        va_start(ap, fmt);
        com_err_va(whoami, code, fmt, ap);
        va_end(ap);
    }
    else if (whoami == NULL && fmt != NULL) {
        const char* def_whoami = "default";
        va_start(ap, fmt);
        com_err_va(def_whoami, code, fmt, ap);
        va_end(ap);
    }
    else if (whoami != NULL && fmt == NULL) {
        const char* def_fmt = "default formatting";
        va_start(ap, def_fmt);
        com_err_va(whoami, code, def_fmt, ap);
        va_end(ap);
    }
    else {
       const char* def_whoami = "default";
       const char* def_fmt = "default formatting";
       va_start(ap, def_fmt);
       com_err_va(def_whoami, code, def_fmt, ap);
       va_end(ap);
    }
}