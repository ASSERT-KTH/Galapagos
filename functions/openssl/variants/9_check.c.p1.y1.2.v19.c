1. Updated variant that checks the error code straight inside the assertion:


check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }

    assert(code == 0);
}


2. Using the ternary operator to provide the error message:  


void check(krb5_error_code code)
{
    const char *errmsg;

    errmsg = (code != 0) ? krb5_get_error_message(ctx, code) : NULL;

    if (errmsg != NULL) {
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }

    assert(code == 0);
}


3. Using a more compact approach by excluding the explicit declaration of 'errmsg':


void check(krb5_error_code code)
{
    if (code != 0) {
        fprintf(stderr, "%s\n", krb5_get_error_message(ctx, code));
        krb5_free_error_message(ctx, krb5_get_error_message(ctx, code));
    }

    assert(code == 0);
}


4. Using logical operator in condition 


void check(krb5_error_code code)
{
    if (code) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    }
    assert(!code);
}


These are all equivalent refactorings that maintain the original functionality of the implementation and keep the error messages, function signatures and functionality matching the original `check` function.