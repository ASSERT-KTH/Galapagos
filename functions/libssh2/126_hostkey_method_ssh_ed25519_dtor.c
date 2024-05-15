hostkey_method_ssh_ed25519_dtor(LIBSSH2_SESSION * session, void **abstract)
{
    libssh2_ed25519_ctx *keyctx = (libssh2_ed25519_ctx*) (*abstract);
    (void)session;

    if(keyctx)
        _libssh2_ed25519_free(keyctx);

    *abstract = NULL;

    return 0;
}