_libssh2_wincng_random(void *buf, size_t len)
{
    int ret;

    if(len > ULONG_MAX) {
        return -1;
    }

    ret = BCryptGenRandom(_libssh2_wincng.hAlgRNG, buf, (ULONG)len, 0);

    return BCRYPT_SUCCESS(ret) ? 0 : -1;
}