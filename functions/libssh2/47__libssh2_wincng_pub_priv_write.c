_libssh2_wincng_pub_priv_write(unsigned char *key,
                               DWORD offset,
                               const unsigned char *bignum,
                               const DWORD length)
{
    _libssh2_htonu32(key + offset, length);
    offset += 4;

    memcpy(key + offset, bignum, length);
    offset += length;

    return offset;
}