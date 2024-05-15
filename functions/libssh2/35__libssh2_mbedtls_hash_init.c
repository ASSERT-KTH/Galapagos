_libssh2_mbedtls_hash_init(mbedtls_md_context_t *ctx,
                           mbedtls_md_type_t mdtype,
                           const unsigned char *key, size_t keylen)
{
    const mbedtls_md_info_t *md_info;
    int ret, hmac;

    md_info = mbedtls_md_info_from_type(mdtype);
    if(!md_info)
        return 0;

    hmac = key ? 1 : 0;

    mbedtls_md_init(ctx);
    ret = mbedtls_md_setup(ctx, md_info, hmac);
    if(!ret) {
        if(hmac)
            ret = mbedtls_md_hmac_starts(ctx, key, keylen);
        else
            ret = mbedtls_md_starts(ctx);
    }

    return ret == 0 ? 1 : 0;
}