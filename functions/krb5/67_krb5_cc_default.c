krb5_cc_default(krb5_context context, krb5_ccache *ccache)
{
    const char *default_name;

    if (!context || context->magic != KV5M_CONTEXT)
        return KV5M_CONTEXT;

    default_name = krb5_cc_default_name(context);
    if (default_name == NULL) {
        /* Could be a bogus context, or an allocation failure, or
           other things.  Unfortunately the API doesn't allow us
           to find out any specifics.  */
        return KRB5_FCC_INTERNAL;
    }

    return krb5_cc_resolve(context, default_name, ccache);
}