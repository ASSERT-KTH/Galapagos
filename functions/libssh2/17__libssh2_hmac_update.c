int _libssh2_hmac_update(libssh2_hmac_ctx *ctx,
                         const void *data, size_t datalen)
{
#ifdef USE_OPENSSL_3
    return EVP_MAC_update(*ctx, data, datalen);
#elif defined(HAVE_OPAQUE_STRUCTS)
/* FIXME: upstream bug as of v5.6.0: datalen is int instead of size_t */
#if defined(LIBSSH2_WOLFSSL)
    return HMAC_Update(*ctx, data, (int)datalen);
#else /* !LIBSSH2_WOLFSSL */
    return HMAC_Update(*ctx, data, datalen);
#endif /* LIBSSH2_WOLFSSL */
#else
    return HMAC_Update(ctx, data, datalen);
#endif
}