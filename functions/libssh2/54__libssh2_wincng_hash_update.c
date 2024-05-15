_libssh2_wincng_hash_update(_libssh2_wincng_hash_ctx *ctx,
                            const void *data, ULONG datalen)
{
    int ret;

    ret = BCryptHashData(ctx->hHash, (PUCHAR)data, datalen, 0);

    return BCRYPT_SUCCESS(ret) ? 0 : -1;
}