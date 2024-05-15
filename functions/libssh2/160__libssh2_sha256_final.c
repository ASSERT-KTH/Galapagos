_libssh2_sha256_final(libssh2_sha256_ctx *ctx,
                      unsigned char *out)
{
#ifdef HAVE_OPAQUE_STRUCTS
    int ret = EVP_DigestFinal(*ctx, out, NULL);
    EVP_MD_CTX_free(*ctx);
    return ret;
#else
    return EVP_DigestFinal(ctx, out, NULL);
#endif
}