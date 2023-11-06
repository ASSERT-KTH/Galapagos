Variant 1:

void check(krb5_error_code code)
{
    const char *errmsg;

    if (0 != code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(0 == code);
    }
} 
 

Variant 2:

void check(krb5_error_code code)
{
    if (!code) return;
    
    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(0 == code);
}
 

Variant 3:

void check(krb5_error_code code)
{
    if (code) 
    {
        const char *errmsg;
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, strstr(errmsg, "\n"));
        krb5_free_error_message(ctx, errmsg);
        assert(!code);
    } 
} 
 

Variant 4:

void check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg;
        errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        fputc('\n', stderr);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}
