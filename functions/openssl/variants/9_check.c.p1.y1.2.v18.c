Variant 1 - Surrounding log block with check:

check(krb5_error_code code)
{
    const char *errmsg;

    if(code) {
        errmsg = krb5_get_error_message(ctx, code);
        if(errmsg) {
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        }

        assert(0);
    }
}


Variant 2 - Change to Do while loop:

check(krb5_error_code code)
{
    const char *errmsg;

    do {
        if (code == 0) break;
        
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);

        assert(code == 0);
    }
    while (0);
}


Variant 3 - If condition to check for success:

check(krb5_error_code code) {
    const char *errmsg;

    if (code == 0) return;
    
    errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    
    assert(code == 0);
}


Variant 4 - Switch-Case Approach

check(krb5_error_code code) {
    const char *errmsg;

    switch(code) {
        case 0:
            return;
        default:
            errmsg = krb5_get_error_message(ctx, code);
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
            assert(false);
    }
}
+