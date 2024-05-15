krb5_auth_con_init(krb5_context context, krb5_auth_context *auth_context)
{
    *auth_context =
        (krb5_auth_context)calloc(1, sizeof(struct _krb5_auth_context));
    if (!*auth_context)
        return ENOMEM;

    /* Default flags, do time not seq */
    (*auth_context)->auth_context_flags =
        KRB5_AUTH_CONTEXT_DO_TIME |  KRB5_AUTH_CONN_INITIALIZED;

    (*auth_context)->checksum_func = NULL;
    (*auth_context)->checksum_func_data = NULL;
    (*auth_context)->negotiated_etype = ENCTYPE_NULL;
    (*auth_context)->magic = KV5M_AUTH_CONTEXT;
    return 0;
}