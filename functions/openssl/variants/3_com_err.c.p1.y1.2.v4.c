Variant 1:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    
    if(true){
        com_err_va(whoami, code, fmt, ap);
    }

    va_end(ap);
}


Variant 2:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    do{
        com_err_va(whoami, code, fmt, ap);
    }while(false);
  
    va_end(ap);
}


Variant 3:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    for( int i=0; i<1; i++){
        com_err_va(whoami, code, fmt, ap);
    }
 
    va_end(ap);
}


Variant 4:

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    switch(true){
        case true:
            com_err_va(whoami, code, fmt, ap); 
            break;
        default:
            break;
    }
  
    va_end(ap);
}
 