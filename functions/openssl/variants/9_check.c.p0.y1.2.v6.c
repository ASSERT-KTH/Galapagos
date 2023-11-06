void check(krb5_error_code code)
{
    if (code) {
        const char *error_msg;
        error_msg = krb5_get_error_message(ctx, code);
        fputs(error_msg, stderr);
        fputs("\n", stderr);
        krb5_free_error_message(ctx, error_msg);
    }
    assert(!code);
}