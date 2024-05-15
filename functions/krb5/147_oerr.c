oerr(krb5_context context, krb5_error_code code, const char *fmt, ...)
{
    unsigned long err;
    va_list ap;
    char *str, buf[128];
    int r;

    if (!code)
        code = KRB5KDC_ERR_PREAUTH_FAILED;

    va_start(ap, fmt);
    r = vasprintf(&str, fmt, ap);
    va_end(ap);
    if (r < 0)
        return code;

    err = ERR_peek_error();
    if (err) {
        krb5_set_error_message(context, code, _("%s: %s"), str,
                               ERR_reason_error_string(err));
    } else {
        krb5_set_error_message(context, code, "%s", str);
    }

    TRACE_PKINIT_OPENSSL_ERROR(context, str);
    while ((err = ERR_get_error()) != 0) {
        ERR_error_string_n(err, buf, sizeof(buf));
        TRACE_PKINIT_OPENSSL_ERROR(context, buf);
    }

    free(str);
    return code;
}