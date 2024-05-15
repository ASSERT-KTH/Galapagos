int _libssh2_hmac_update(libssh2_hmac_ctx *ctx,
                         const void *data, size_t datalen)
{
    int ret = mbedtls_md_hmac_update(ctx, data, datalen);

    return ret == 0 ? 1 : 0;
}