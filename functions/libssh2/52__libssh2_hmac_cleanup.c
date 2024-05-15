void _libssh2_hmac_cleanup(libssh2_hmac_ctx *ctx)
{
    BCryptDestroyHash(ctx->hHash);
    ctx->hHash = NULL;

    _libssh2_wincng_safe_free(ctx->pbHashObject, ctx->dwHashObject);
    ctx->pbHashObject = NULL;
    ctx->dwHashObject = 0;
}