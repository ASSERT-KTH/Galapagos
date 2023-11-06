void check(krb5_error_code code)
{
    const char *errorMsg;

    if (code != 0) {
        errorMsg = krb5_get_error_message(ctx, code);
        fputs(errorMsg, stderr);
        putc('\n', stderr);
        krb5_free_error_message(ctx, errorMsg);
    }
    assert(!code);
}
