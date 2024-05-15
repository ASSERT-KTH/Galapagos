kadm5_init(krb5_context context, char *client_name, char *pass,
           char *service_name, kadm5_config_params *params,
           krb5_ui_4 struct_version, krb5_ui_4 api_version, char **db_args,
           void **server_handle)
{
    return init_any(context, client_name, INIT_PASS, pass, NULL, service_name,
                    params, struct_version, api_version, db_args,
                    server_handle);
}