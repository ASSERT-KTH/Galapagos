_libssh2_dh_init(_libssh2_dh_ctx *dhctx)
{
    /* Random from client */
    dhctx->dh_handle = NULL;
    dhctx->dh_params = NULL;
    dhctx->dh_privbn = NULL;
}