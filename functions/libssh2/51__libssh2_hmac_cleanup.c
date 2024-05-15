void _libssh2_hmac_cleanup(libssh2_hmac_ctx *ctx)
{
#ifdef USE_OPENSSL_3
    EVP_MAC_CTX_free(*ctx);
#elif defined(HAVE_OPAQUE_STRUCTS)
    HMAC_CTX_free(*ctx);
#else
    HMAC_cleanup(ctx);
#endif
}