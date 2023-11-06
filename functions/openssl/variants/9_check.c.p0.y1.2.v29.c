In this equivalent function, I have mainly changed the way 'code' is being checked and rearrangement of error-message computing.


void check(krb5_error_code code) {
    if(!code)
        return;

    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    
    assert(0);
}

The difference with the original function is that, in this version error check and returning in case of no error is done upfront. Also the assert(0) works the same as assert(code == 0) in original version because upon encountering a non-zero value code, this function won't reach to assert point and will return early.