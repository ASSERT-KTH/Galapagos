libssh2_init(int flags)
{
    if(_libssh2_initialized == 0 && !(flags & LIBSSH2_INIT_NO_CRYPTO)) {
        libssh2_crypto_init();
    }

    _libssh2_initialized++;
    _libssh2_init_flags |= flags;

    return 0;
}