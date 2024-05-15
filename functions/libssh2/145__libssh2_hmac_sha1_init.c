int _libssh2_hmac_sha1_init(libssh2_hmac_ctx *ctx,
                            void *key, size_t keylen)
{
    return libssh2_os400qc3_hmac_init(ctx, Qc3_SHA1,                    \
                                      SHA_DIGEST_LENGTH,                \
                                      key, keylen);
}