hostkey_method_ssh_rsa_dtor(LIBSSH2_SESSION * session, void **abstract)
{
    libssh2_rsa_ctx *rsactx = (libssh2_rsa_ctx *) (*abstract);
    (void)session;

    _libssh2_rsa_free(rsactx);

    *abstract = NULL;

    return 0;
}