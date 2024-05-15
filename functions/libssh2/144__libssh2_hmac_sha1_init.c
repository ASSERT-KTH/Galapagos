int _libssh2_hmac_sha1_init(libssh2_hmac_ctx *ctx,
                            void *key, size_t keylen)
{
#ifdef USE_OPENSSL_3
    return _libssh2_hmac_init(ctx, key, keylen, OSSL_DIGEST_NAME_SHA1);
#elif defined(HAVE_OPAQUE_STRUCTS)
    return HMAC_Init_ex(*ctx, key, (int)keylen, EVP_sha1(), NULL);
#else
    return HMAC_Init_ex(ctx, key, (int)keylen, EVP_sha1(), NULL);
#endif
}