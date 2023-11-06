1. Rearranging code blocks:

check(krb5_error_code code)
{
    assert(code == 0);

    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
}


2. Using `else` statements:

check(krb5_error_code code)
{
    const char *errmsg;

    if (code == 0) {
        assert(true);
    } else {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
}


3. Using negation in the assertion:

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(!(code != 0));
    }
}


4. Combine them:

check(krb5_error_code code)
{
    const char *errmsg;

    if (code == 0) {
        assert(true);
    } else {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(!(code != 0));
    }
} 


5. Inline the `errmsg` variable 

check(krb5_error_code code)
{
    if (code != 0) {
        fprintf(stderr, "%s\n", krb5_get_error_message(ctx, code));
        krb5_free_error_message(ctx, krb5_get_error_message(ctx, code));
        assert(code == 0);
    }
}


6. Simply exit from function if there's no error: 
 
check(krb5_error_code code)
{
    if (code == 0) {
        return; 
    }
    
    const char *errmsg = krb5_get_error_message(ctx, code);
    fprintf(stderr, "%s\n", errmsg);
    krb5_free_error_message(ctx, errmsg);
    assert(code != 0);
}  
