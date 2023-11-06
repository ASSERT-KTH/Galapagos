check(krb5_error_code code)
{
    const char *errmsg;

    if (code) {
        errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        putchar('\n');
        krb5_free_error_message(ctx, errmsg);
    }
    if (code) exit(1);
}