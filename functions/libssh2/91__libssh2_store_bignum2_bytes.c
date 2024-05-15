int _libssh2_store_bignum2_bytes(unsigned char **buf,
                                 const unsigned char *bytes,
                                 size_t len)
{
    uint32_t len_stored;
    uint32_t extraByte;
    const unsigned char *p;

    for(p = bytes; len > 0 && *p == 0; --len, ++p) {}

    extraByte = (len > 0 && (p[0] & 0x80) != 0);
    len_stored = (uint32_t)len;
    if(extraByte && len_stored == 0xffffffff)
        len_stored--;
    _libssh2_store_u32(buf, len_stored + extraByte);

    if(extraByte) {
        *buf[0] = 0;
        *buf += 1;
    }

    if(len_stored) {
        memcpy(*buf, p, len_stored);
        *buf += len_stored;
    }

    assert(len_stored == len);
    return len_stored == len;
}