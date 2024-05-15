kadm5_free_policy_ent(void *server_handle, kadm5_policy_ent_t val)
{
    krb5_tl_data *tl_next;

    _KADM5_CHECK_HANDLE(server_handle);

    if (val == NULL)
        return KADM5_OK;

    free(val->policy);
    free(val->allowed_keysalts);
    for (; val->tl_data; val->tl_data = tl_next) {
        tl_next = val->tl_data->tl_data_next;
        free(val->tl_data->tl_data_contents);
        free(val->tl_data);
    }
    memset(val, 0, sizeof(*val));
    return KADM5_OK;
}