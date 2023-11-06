1. Add optional error logging flag.


check(krb5_error_code code, int enableLog)
{
    const char *errmsg;

    if (code != 0) {
        if (enableLog) {
            errmsg = krb5_get_error_message(ctx, code);
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        }
    }    
    assert(code == 0);
}


2. Variations on assert usage.


check(krb5_error_code code)
{
    const char *errmsg;

    assert(code == 0 && "Assertion failed: Error code is not 0");

    if (code != 0) {
         errmsg = krb5_get_error_message(ctx, code);
         fprintf(stderr, "%s\n", errmsg);
         krb5_free_error_message(ctx, errmsg);
    }
}


3. Modified style of checking the error code.


check(krb5_error_code code)
{
    const char *errmsg;

    if (code) { /* equivalent to: if (code !=0) */
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(code==0);
    }
}


4. Turned to ternary operation.


check(krb5_error_code code)
{
    if (code)
        code == 0 ? (void) 0 :
        ({
            const char *errmsg = krb5_get_error_message(ctx, code);
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
            assert(0);
         });
}
