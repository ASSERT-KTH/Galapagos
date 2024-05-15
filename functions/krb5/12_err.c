err(krb5_context ctx, krb5_error_code code, const char *fmt, ...)
{
    va_list ap;
    char *msg;
    const char *errmsg = NULL;

    va_start(ap, fmt);
    if (vasprintf(&msg, fmt, ap) < 0)
        exit(1);
    va_end(ap);
    if (ctx && code)
        errmsg = krb5_get_error_message(ctx, code);
    if (errmsg)
        fprintf(stderr, "t_princ: %s: %s\n", msg, errmsg);
    else
        fprintf(stderr, "t_princ: %s\n", msg);
    exit(1);
}