Here is a different but equivalent implementation:

void check(krb5_error_code code)
{
    if (code) {
        const char *error;

        error = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", error);
        krb5_free_error_message(ctx, error);

        exit(1);
    }
}