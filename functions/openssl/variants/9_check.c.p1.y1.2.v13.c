Variant 1:


void check(krb5_error_code code) 
{
    const char *errmsg;

    if (code) 
    {
        errmsg = krb5_get_error_message(ctx, code);
        if (errmsg != NULL) fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    if (code != 0) abort();
}


Variant 2:


void check(krb5_error_code code) 
{
    const char *errmsg = (code != 0) ? krb5_get_error_message(ctx, code) : NULL;

    if (errmsg)
    {
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    if (code) exit(1);
}


Variants 3:


void check(krb5_error_code code) 
{
    if (!code) return; 

    const char *errmsg = krb5_get_error_message(ctx, code);

    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
        
    abort();
}
