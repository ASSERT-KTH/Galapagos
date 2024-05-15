int _libssh2_hmac_update(libssh2_hmac_ctx *ctx,
                         const void *data, size_t datalen)
{
    int ret = _libssh2_wincng_hash_update(ctx, data, (ULONG) datalen);

    return ret == 0 ? 1 : 0;
}