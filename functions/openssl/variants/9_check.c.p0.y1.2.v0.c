void check(krb5_error_code code)
{
    const char *error_message;

    if (code) {
        error_message = krb5_get_error_message(ctx, code);
        fputs(error_message, stderr);
        fputs("\n", stderr);
        krb5_free_error_message(ctx, error_message);
    }

    if (code != 0) abort();
}