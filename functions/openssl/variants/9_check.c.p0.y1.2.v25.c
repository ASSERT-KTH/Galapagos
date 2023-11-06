void check(krb5_error_code code)
{
    if (code) {
        const char *msg;
        msg = krb5_get_error_message(ctx, code);
        fputs(msg, stderr);
        krb5_free_error_message(ctx, msg);
        fputs("\n", stderr);
    }
    assert(!code);
}