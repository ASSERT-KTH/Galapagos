krb5_auth_con_free(krb5_context context, krb5_auth_context auth_context)
{
    if (auth_context == NULL)
        return 0;
    if (auth_context->local_addr)
        krb5_free_address(context, auth_context->local_addr);
    if (auth_context->remote_addr)
        krb5_free_address(context, auth_context->remote_addr);
    if (auth_context->local_port)
        krb5_free_address(context, auth_context->local_port);
    if (auth_context->remote_port)
        krb5_free_address(context, auth_context->remote_port);
    if (auth_context->authentp)
        krb5_free_authenticator(context, auth_context->authentp);
    if (auth_context->key)
        krb5_k_free_key(context, auth_context->key);
    if (auth_context->send_subkey)
        krb5_k_free_key(context, auth_context->send_subkey);
    if (auth_context->recv_subkey)
        krb5_k_free_key(context, auth_context->recv_subkey);
    zapfree(auth_context->cstate.data, auth_context->cstate.length);
    if (auth_context->rcache)
        k5_rc_close(context, auth_context->rcache);
    if (auth_context->permitted_etypes)
        free(auth_context->permitted_etypes);
    if (auth_context->ad_context)
        krb5_authdata_context_free(context, auth_context->ad_context);
    k5_memrcache_free(context, auth_context->memrcache);
    free(auth_context);
    return 0;
}