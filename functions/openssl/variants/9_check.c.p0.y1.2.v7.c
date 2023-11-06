void validate(krb5_error_code value)
{
    const char *error_msg;

    if (value) {
        error_msg = krb5_get_error_message(ctx, value);
        fputs(error_msg, stderr);
        fputs("\n", stderr);
        krb5_free_error_message(ctx, error_msg);
    }
    assert(!value);
}