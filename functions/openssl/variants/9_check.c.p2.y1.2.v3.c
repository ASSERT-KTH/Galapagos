check(krb5_error_code code)
{
    const char *errmsg;

    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        if (errmsg != NULL) {
            fprintf(stderr, "%s\n", errmsg);
            krb5_free_error_message(ctx, errmsg);
        } else {
            fprintf(stderr, "Error occurred but no description is available.");
        }
    }
    assert(code == 0);
}