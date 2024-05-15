int _libssh2_store_str(unsigned char **buf, const char *str, size_t len)
{
    uint32_t len_stored = (uint32_t)len;

    _libssh2_store_u32(buf, len_stored);
    if(len_stored) {
        memcpy(*buf, str, len_stored);
        *buf += len_stored;
    }

    assert(len_stored == len);
    return len_stored == len;
}