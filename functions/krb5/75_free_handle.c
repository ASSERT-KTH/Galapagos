free_handle(kadm5_server_handle_t handle)
{
    if (handle == NULL)
        return;

    destroy_pwqual(handle);
    k5_kadm5_hook_free_handles(handle->context, handle->hook_handles);
    ulog_fini(handle->context);
    krb5_db_fini(handle->context);
    krb5_free_principal(handle->context, handle->current_caller);
    kadm5_free_config_params(handle->context, &handle->params);
    free(handle->lhandle);
    free_db_args(handle);
    free(handle);
}