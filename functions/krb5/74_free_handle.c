free_handle(kadm5_server_handle_t handle)
{
    kadm5_ret_t ret = 0;
    OM_uint32 minor_stat;
    krb5_ccache ccache;

    if (handle == NULL)
        return 0;

    if (handle->destroy_cache && handle->cache_name != NULL) {
        ret = krb5_cc_resolve(handle->context, handle->cache_name, &ccache);
        if (!ret)
            ret = krb5_cc_destroy(handle->context, ccache);
    }
    free(handle->cache_name);
    (void)gss_release_cred(&minor_stat, &handle->cred);
    if (handle->clnt != NULL && handle->clnt->cl_auth != NULL)
        AUTH_DESTROY(handle->clnt->cl_auth);
    if (handle->clnt != NULL)
        clnt_destroy(handle->clnt);
    if (handle->client_socket != -1)
        close(handle->client_socket);
    free(handle->lhandle);
    kadm5_free_config_params(handle->context, &handle->params);
    free(handle);

    return ret;
}