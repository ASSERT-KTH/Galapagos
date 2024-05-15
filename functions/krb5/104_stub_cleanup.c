stub_cleanup(kadm5_server_handle_t handle, char *princ_str,
             gss_buffer_t client_name, gss_buffer_t service_name)
{
    OM_uint32 minor_stat;

    auth_end(handle->context);
    free_server_handle(handle);
    free(princ_str);
    gss_release_buffer(&minor_stat, client_name);
    gss_release_buffer(&minor_stat, service_name);
}