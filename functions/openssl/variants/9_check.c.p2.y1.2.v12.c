check(krb5_error_code code)
{
    const char *errmsg;

    assert(code == 0);

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        krb5_free_error_message(ctx, errmsg);
    }
}