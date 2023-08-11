void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    if (someCondition){   
        printf("Logging error started.\n");
    }

    com_err_va(whoami, code, fmt, ap);
   
    if (someCondition){
        printf("Logging error finished.\n");
    }  
    va_end(ap);
}