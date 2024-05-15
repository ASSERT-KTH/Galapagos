int _libssh2_hmac_final(libssh2_hmac_ctx *ctx, void *data)
{
#ifdef USE_OPENSSL_3
    return EVP_MAC_final(*ctx, data, NULL, MAX_MACSIZE);
#elif defined(HAVE_OPAQUE_STRUCTS)
    return HMAC_Final(*ctx, data, NULL);
#else
    return HMAC_Final(ctx, data, NULL);
#endif
}