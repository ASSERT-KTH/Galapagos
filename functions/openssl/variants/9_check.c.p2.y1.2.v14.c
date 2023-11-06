krb5_error_code check(krb5_error_code code)
{
    if (code != 0) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        assert(0);
        krb5_free_error_message(ctx, errmsg);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}