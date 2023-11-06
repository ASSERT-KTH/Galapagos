void check(krb5_error_code code)
{
    if (code) {
        const char *error;

        error = krb5_get_error_message(ctx, code);
        fputs(error, stderr);
        fputc('\n', stderr);
        krb5_free_error_message(ctx, error);
    }
    assert(!code);
}