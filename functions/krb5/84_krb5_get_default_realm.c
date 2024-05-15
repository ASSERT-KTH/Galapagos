krb5_get_default_realm(krb5_context context, char **realm_out)
{
    krb5_error_code ret;

    *realm_out = NULL;

    if (context == NULL || context->magic != KV5M_CONTEXT)
        return KV5M_CONTEXT;

    if (context->default_realm == NULL) {
        ret = get_default_realm(context, &context->default_realm);
        if (ret)
            return ret;
    }
    *realm_out = strdup(context->default_realm);
    return (*realm_out == NULL) ? ENOMEM : 0;
}