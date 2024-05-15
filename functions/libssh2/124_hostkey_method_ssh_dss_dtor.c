hostkey_method_ssh_dss_dtor(LIBSSH2_SESSION * session, void **abstract)
{
    libssh2_dsa_ctx *dsactx = (libssh2_dsa_ctx *) (*abstract);
    (void)session;

    _libssh2_dsa_free(dsactx);

    *abstract = NULL;

    return 0;
}