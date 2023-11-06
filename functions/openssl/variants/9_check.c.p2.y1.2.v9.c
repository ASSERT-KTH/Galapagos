Here is a variant of your function in C that maintains its original functionality but subtly changes its behavior:


check(krb5_error_code code)
{
    const char *errmsg;

    switch(code){
        case 0 :
          break;  
        
        default :
            errmsg = krb5_get_error_message(ctx, code);
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
            assert(0);
    }
}
