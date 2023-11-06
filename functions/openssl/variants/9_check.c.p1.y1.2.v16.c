1. Using a ternary operator to initialize errmsg.

check(krb5_error_code code)
{
    const char *errmsg = (code != 0) ? krb5_get_error_message(ctx, code) : NULL;

    if (code != 0) {
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    
    assert(code == 0);
}


2. Assigning the boolean expression result to bool variable to apply less computation

check(krb5_error_code code)
{
    bool isCodeNotZero = code != 0;
    const char *errmsg;

    if (isCodeNotZero) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    
    assert(!isCodeNotZero);
}


3. Simplifying the assignment to errmsg within code.

check(krb5_error_code code)
{
    const char *errmsg;

    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    
    assert(!code);
}


4. Combine function calls into one line.

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        fprintf(stderr, "%s\n", errmsg = krb5_get_error_message(ctx, code));
        krb5_free_error_message(ctx, errmsg);
    }
    
    assert(code == 0);
}
