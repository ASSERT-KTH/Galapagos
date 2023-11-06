1. Remove variables and inline usage:


check(krb5_error_code code)
{
    if (code != 0) {
        fprintf(stderr, "%s\n", krb5_get_error_message(ctx, code));
        krb5_free_error_message(ctx, krb5_get_error_message(ctx, code));
    }
    assert(code == 0);
}


2. Changing the logic in assert


check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(!code);
    }
    assert(code == 0);
}


3. Making the assert in an else condition


check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    } else {
        assert(code == 0);
    }
}


4. Single out the assertion from if block
  

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(code >= 0 && code == 0);
}

      
Bear in mind the functionality stays the same only assuming `code` is always non-negative. If `code` could be a negative number, an assertion like `assert(code >= 0);` could behave differently than the original one. 

5. Overwriting return code temporarily


check(krb5_error_code code)
{
    const char *errmsg;

    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        code = 0;
    }
    assert(code == 0);
}

      
This will clear the error after reporting it but before asserting on it, preserving the assert behavior from the original code given that there's no early return after the error's been handled but before the assertion.