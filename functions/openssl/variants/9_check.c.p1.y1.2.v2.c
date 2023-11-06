Variant 1:

check(krb5_error_code code)
{
    if (code) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(!code);
    }
}


Variant 2:

check(krb5_error_code code)
{
    assert(code == 0);
    
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        fputs("\n", stderr);
        krb5_free_error_message(ctx, errmsg);
    }
}


Variant 3:

check(krb5_error_code code)
{
    if (code == 0) return;
    
    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(code == 0);
}


Variant 4:

check(krb5_error_code code)
{
    if (!code) return;
    
    const char *errmsg = krb5_get_error_message(ctx, code);
    fputs(errmsg, stderr);
    fputs("\n", stderr);
    krb5_free_error_message(ctx, errmsg);
    assert(!code);
}
