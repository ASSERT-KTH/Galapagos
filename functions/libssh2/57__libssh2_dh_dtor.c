_libssh2_dh_dtor(_libssh2_dh_ctx *dhctx)
{
    if(dhctx->dh_handle) {
        BCryptDestroyKey(dhctx->dh_handle);
        dhctx->dh_handle = NULL;
    }
    if(dhctx->dh_params) {
        /* Since public dh_params are shared in clear text,
         * we don't need to securely zero them out here */
        free(dhctx->dh_params);
        dhctx->dh_params = NULL;
    }
    if(dhctx->dh_privbn) {
        _libssh2_wincng_bignum_free(dhctx->dh_privbn);
        dhctx->dh_privbn = NULL;
    }
}