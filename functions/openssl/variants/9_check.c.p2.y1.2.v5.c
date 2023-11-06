check(krb5_error_code code)
{
    const char *errmsg;
    
    if (code != 0) {
        errmsg = krb5_get_error_message(ctx, code);
        fputs(errmsg, stderr);
        fputc('\n', stderr);
        krb5_free_error_message(ctx, errmsg);
    }
    else
        assert(1);
}