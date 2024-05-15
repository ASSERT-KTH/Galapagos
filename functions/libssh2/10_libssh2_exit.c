libssh2_exit(void)
{
    if(_libssh2_initialized == 0)
        return;

    _libssh2_initialized--;

    if(_libssh2_initialized == 0 &&
       !(_libssh2_init_flags & LIBSSH2_INIT_NO_CRYPTO)) {
        libssh2_crypto_exit();
    }

    return;
}