Here is your substitute implementation:


check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        fputc('\n', stderr);
        krb5_free_error_message(ctx, errmsg);
        assert(code == 0);
    }
}
