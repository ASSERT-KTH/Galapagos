hostkey_method_ssh_ecdsa_dtor(LIBSSH2_SESSION * session, void **abstract)
{
    libssh2_ecdsa_ctx *keyctx = (libssh2_ecdsa_ctx *) (*abstract);
    (void)session;

    if(keyctx)
        _libssh2_ecdsa_free(keyctx);

    *abstract = NULL;

    return 0;
}