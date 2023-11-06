void check(krb5_error_code code)
{
    if (0 != code) {
        const char *errmsg = krb5_get_error_message(ctx, code);
        krb5_free_error_message(ctx, errmsg);
        fputs(errmsg, stderr);
        putchar('\n');
    }
    if(code) { assert(false);  }
}