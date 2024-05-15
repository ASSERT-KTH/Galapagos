int _libssh2_hmac_ctx_init(libssh2_hmac_ctx *ctx)
{
#ifdef USE_OPENSSL_3
    *ctx = NULL;
    return 1;
#elif defined(HAVE_OPAQUE_STRUCTS)
    *ctx = HMAC_CTX_new();
    return *ctx ? 1 : 0;
#else
    HMAC_CTX_init(ctx);
    return 1;
#endif
}