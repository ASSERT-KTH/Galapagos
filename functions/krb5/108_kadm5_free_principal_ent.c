kadm5_free_principal_ent(void *server_handle, kadm5_principal_ent_t val)
{
    kadm5_server_handle_t handle = server_handle;
    krb5_tl_data *tl;
    int i;

    _KADM5_CHECK_HANDLE(server_handle);

    if (!val)
        return KADM5_OK;

    krb5_free_principal(handle->context, val->principal);
    krb5_free_principal(handle->context, val->mod_name);
    free(val->policy);
    if (val->n_key_data) {
        for (i = 0; i < val->n_key_data; i++)
            krb5_free_key_data_contents(handle->context, &val->key_data[i]);
        free(val->key_data);
    }

    while (val->tl_data) {
        tl = val->tl_data->tl_data_next;
        free(val->tl_data->tl_data_contents);
        free(val->tl_data);
        val->tl_data = tl;
    }
    return KADM5_OK;
}