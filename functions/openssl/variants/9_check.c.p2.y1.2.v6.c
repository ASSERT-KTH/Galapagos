check(krb5_error_code code) 
{
    const char *errmsg;

    /*Adding an Extra Check Before Assertion*/
    if (code == 0) {
        return;
    } else {
        errmsg = krb5_get_error_message(ctx, code);
        fprintf(stderr, "%s\n", errmsg);
        krb5_free_error_message(ctx, errmsg);

        /*Relocating Assertion in the Else block*/
        assert(code == 0);
    }
}