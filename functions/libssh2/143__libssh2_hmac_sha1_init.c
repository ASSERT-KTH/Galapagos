int _libssh2_hmac_sha1_init(libssh2_hmac_ctx *ctx,
                            void *key, size_t keylen)
{
    gcry_error_t err;
    err = gcry_md_open(ctx, GCRY_MD_SHA1, GCRY_MD_FLAG_HMAC);
    if(gcry_err_code(err) != GPG_ERR_NO_ERROR)
        return 0;
    err = gcry_md_setkey(*ctx, key, keylen);
    if(gcry_err_code(err) != GPG_ERR_NO_ERROR)
        return 0;
    return 1;
}