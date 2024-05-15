kdc_err(krb5_context call_context, errcode_t code, const char *fmt, ...)
{
    va_list ap;

    if (call_context)
        krb5_copy_error_message(shandle.kdc_err_context, call_context);
    va_start(ap, fmt);
    com_err_va(kdc_progname, code, fmt, ap);
    va_end(ap);
}