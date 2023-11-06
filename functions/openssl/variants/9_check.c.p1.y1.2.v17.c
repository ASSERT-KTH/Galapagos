Variant 1:

check(krb5_error_code code)
{
    if (code == 0) return; 

    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(code == 0);
}


Variant 2:

check(krb5_error_code code)
{     
    const char _unused *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        (void)fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }

    assert(code == 0);
}


Variant 3:

check(krb5_error_code code)
{   
    const char *errmsg;

    do {
        if(code == 0) break;
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    } while(0);

    assert(code == 0);
}


Variant 4:

check(krb5_error_code code)
{
    if (!code)
        return;

    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(!code);
}
