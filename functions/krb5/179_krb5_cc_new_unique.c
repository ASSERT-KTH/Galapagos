krb5_cc_new_unique(
    krb5_context context,
    const char *type,
    const char *hint,
    krb5_ccache *id)
{
    const krb5_cc_ops *ops;
    krb5_error_code err;

    *id = NULL;

    TRACE_CC_NEW_UNIQUE(context, type);
    err = krb5int_cc_getops(context, type, &ops);
    if (err)
        return err;

    return ops->gen_new(context, id);
}