1. Change of conditions in assert statement:

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

2. Adding else clause to handle zero case although functionally it won't change due to assert statement

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
    } 
    else {
        assert(code == 0);  
    }
}

3. Return control in case of error itself after freeing the error message

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        return;
    }
    assert(code == 0);
}

4. Display an additional message when assert fails

check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(code == 0 && "KRB5 error occurred!!");
    }
}

5. Using switch-case instead of if condition

check(krb5_error_code code)
{
    const char *errmsg;

    switch(code){
        case 0: assert(code == 0);
                break;
        default: errmsg = krb5_get_error_message(ctx, code);
                 fprintf(stderr, "%s\n", errmsg);
                 krb5_free_error_message(ctx, errmsg);
    }    
}
