check(krb5_error_code code)
{
    if (code == 0) {
        assert(code == 0);
    } else {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fremag(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);
        assert(false);     //Always trigger assert after displaying error message
    }
}