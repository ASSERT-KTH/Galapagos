int _libssh2_hmac_sha1_init(libssh2_hmac_ctx *ctx,
                            void *key, size_t keylen)
{
    int ret = _libssh2_wincng_hash_init(ctx, _libssh2_wincng.hAlgHmacSHA1,
                                        SHA_DIGEST_LENGTH,
                                        key, (ULONG) keylen);

    return ret == 0 ? 1 : 0;
}