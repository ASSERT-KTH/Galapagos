Variant 1:
Removing const modifier

check(krb5_error_code code)
{
    char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}


Variant 2:
Separate the assert statement into own if block

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    if(code != 0) {
        assert(false);
    } else {
        assert(true);
    }
}


Variant 3:
Using else before the assertion

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    } 
    else {
        assert(code == 0);
    }
}


Variant 4:
Curly braces removed from if block

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0)
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    
    assert(code == 0);
}
