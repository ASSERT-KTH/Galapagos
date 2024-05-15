_libssh2_wincng_safe_free(void *buf, size_t len)
{
    if(!buf)
        return;

    if(len > 0)
        _libssh2_explicit_zero(buf, len);

    free(buf);
}