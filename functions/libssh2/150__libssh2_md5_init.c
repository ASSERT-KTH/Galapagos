_libssh2_md5_init(libssh2_md5_ctx *ctx)
{
    /* MD5 digest is not supported in OpenSSL FIPS mode
     * Trying to init it will result in a latent OpenSSL error:
     * "digital envelope routines:FIPS_DIGESTINIT:disabled for fips"
     * So, just return 0 in FIPS mode
     */
#if OPENSSL_VERSION_NUMBER >= 0x000907000L && \
    !defined(USE_OPENSSL_3) && \
    !defined(LIBRESSL_VERSION_NUMBER)

    if(FIPS_mode())
        return 0;
#endif

#ifdef HAVE_OPAQUE_STRUCTS
    *ctx = EVP_MD_CTX_new();

    if(!*ctx)
        return 0;

    if(EVP_DigestInit(*ctx, EVP_get_digestbyname("md5")))
        return 1;

    EVP_MD_CTX_free(*ctx);
    *ctx = NULL;

    return 0;
#else
    EVP_MD_CTX_init(ctx);
    return EVP_DigestInit(ctx, EVP_get_digestbyname("md5"));
#endif
}