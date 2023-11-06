void check(krb5_error_code code)
{
    const char *err_msg;
    if (code) {
        err_msg = krb5_get_error_message(ctx, code);
        fputs(err_msg, stderr);
        fputs("\n", stderr);
        krb5_free_error_message(ctx, err_msg);
    }
    /* assertion statements handle the abort cases by throwing exceptions where necessary */
    assert(!code); 
}