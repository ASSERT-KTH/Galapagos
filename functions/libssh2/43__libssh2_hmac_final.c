int _libssh2_hmac_final(libssh2_hmac_ctx *ctx, void *data)
{
    unsigned char *res = gcry_md_read(*ctx, 0);

    if(!res)
        return 0;

    memcpy(data, res, gcry_md_get_algo_dlen(gcry_md_get_algo(*ctx)));

    return 1;
}