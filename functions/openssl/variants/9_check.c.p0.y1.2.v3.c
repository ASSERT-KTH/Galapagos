void check(krb5_error_code code) {
    const char *errmsg;

    if (code == 0) {
        assert(code == 0);
        return;
    }

    errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);  
    krb5_free_error_message(ctx, errmsg);
        
    assert(code == 0);
}