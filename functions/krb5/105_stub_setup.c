stub_setup(krb5_ui_4 api_version, struct svc_req *rqstp, krb5_principal princ,
           kadm5_server_handle_t *handle_out, krb5_ui_4 *api_version_out,
           gss_buffer_t client_name_out, gss_buffer_t service_name_out,
           char **princ_str_out)
{
    kadm5_ret_t ret;

    ret = new_server_handle(api_version, rqstp, handle_out);
    if (ret)
        return ret;

    ret = check_handle(*handle_out);
    if (ret)
        return ret;

    *api_version_out = (*handle_out)->api_version;

    if (setup_gss_names(rqstp, client_name_out, service_name_out) < 0)
        return KADM5_FAILURE;

    if (princ_str_out != NULL) {
        if (princ == NULL)
            return KADM5_BAD_PRINCIPAL;
        if (krb5_unparse_name((*handle_out)->context, princ, princ_str_out))
            return KADM5_BAD_PRINCIPAL;
    }

    return KADM5_OK;
}