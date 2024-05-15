kadm5_get_principal(void *server_handle,
                    krb5_principal princ, kadm5_principal_ent_t ent,
                    long mask)
{
    gprinc_arg  arg;
    gprinc_ret  r;
    kadm5_server_handle_t handle = server_handle;

    CHECK_HANDLE(server_handle);

    if(princ == NULL)
        return EINVAL;
    arg.princ = princ;
    arg.mask = mask;
    arg.api_version = handle->api_version;
    memset(&r, 0, sizeof(gprinc_ret));
    if (get_principal_2(&arg, &r, handle->clnt))
        eret();
    if (r.code == 0)
        memcpy(ent, &r.rec, sizeof(r.rec));

    return r.code;
}