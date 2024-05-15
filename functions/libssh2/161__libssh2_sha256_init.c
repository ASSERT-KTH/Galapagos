_libssh2_sha256_init(libssh2_sha256_ctx *ctx)
{
#ifdef HAVE_OPAQUE_STRUCTS
    *ctx = EVP_MD_CTX_new();

    if(!*ctx)
        return 0;

    if(EVP_DigestInit(*ctx, EVP_get_digestbyname("sha256")))
        return 1;

    EVP_MD_CTX_free(*ctx);
    *ctx = NULL;

    return 0;
#else
    EVP_MD_CTX_init(ctx);
    return EVP_DigestInit(ctx, EVP_get_digestbyname("sha256"));
#endif
}