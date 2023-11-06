1) Variant using early return mechanism:

void check(krb5_error_code code)
{
    if (!code)
        return;

    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);

    assert(0);
}


2) Single line `if` implementation:

void check(krb5_error_code code)
{
    const char *errmsg;

    if(code) errmsg = krb5_get_error_message(ctx, code), fprintf(stderr, "%s\n", errmsg), krb5_free_error_message(ctx, errmsg), assert(0);
}


3) Variant with inverse assertion:

void check(krb5_error_code code)
{
    const char *errmsg;

    if(code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(!code);
}

4) Reducing local variable scope:

void check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}
 

5) Use of `else` statement: 

void check(krb5_error_code code)
{
    if(code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }else assert(0);
}
