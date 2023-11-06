Option 1 - Different assertion transfer style:

check(krb5_error_code code)
{
    const char *errmsg;

    if (code == 0)
        return;
    
    errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);

    exit(EXIT_FAILURE);
}



Option 2 - Switch the order of statements within the `if` block

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        krb5_free_error_message(ctx, errmsg);
        fprintf(stderr, "%s\n", errmsg);
    }
    assert(code == 0);
}


Option 3 - Use ternary operator for extra condition checks:

check(krb5_error_code code)
{
    const char *errmsg;

    errmsg = (code != 0) ? krb5_get_error_message(ctx, code) : NULL;
    if(errmsg) {
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code == 0);
}

Option 4 - Inline error messages:

check(krb5_error_code code)
{
    if (code != 0) {
        fprintf(stderr, "%s\n", krb5_get_error_message(ctx, code));
         krb5_free_error_message(ctx, krb5_get_error_message(ctx, code));
    }
    assert(code == 0);
}
