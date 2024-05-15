_libssh2_wincng_hash(const unsigned char *data, ULONG datalen,
                     BCRYPT_ALG_HANDLE hAlg,
                     unsigned char *hash, ULONG hashlen)
{
    _libssh2_wincng_hash_ctx ctx;
    int ret;

    ret = _libssh2_wincng_hash_init(&ctx, hAlg, hashlen, NULL, 0);
    if(!ret) {
        ret = _libssh2_wincng_hash_update(&ctx, data, datalen);
        ret |= _libssh2_wincng_hash_final(&ctx, hash);
    }

    return ret;
}