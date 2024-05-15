_libssh2_sha256_update(libssh2_sha256_ctx *ctx,
                       const void *data, size_t len)
{
#ifdef HAVE_OPAQUE_STRUCTS
    return EVP_DigestUpdate(*ctx, data, len);
#else
    return EVP_DigestUpdate(ctx, data, len);
#endif
}