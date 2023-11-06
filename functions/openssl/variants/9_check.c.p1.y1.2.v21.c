Variant 1:

check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    else {
        assert(code == 0);
    }
}


Variant 2:

check(krb5_error_code code)
{
    const char *errmsg;
    
    assert(code == 0);
    
    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        exit(1);
    }
}


Variant 3:

check(krb5_error_code code)
{
    const char *errmsg;
    
    if(code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(code == 0);
    }
}


Notice: All these variants can influence the control flow of the program or trigger different behavior when `code != 0`. Reading the surrounding code or knowing how the function needs to react depending on `code`  helps choosing the right variant.+A11:A16