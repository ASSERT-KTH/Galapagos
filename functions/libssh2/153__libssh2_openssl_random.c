_libssh2_openssl_random(void *buf, size_t len)
{
    if(len > INT_MAX) {
        return -1;
    }

    return RAND_bytes(buf, (int)len) == 1 ? 0 : -1;
}