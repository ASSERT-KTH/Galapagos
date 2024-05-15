void _libssh2_openssl_crypto_init(void)
{
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
    OpenSSL_add_all_algorithms();
    OpenSSL_add_all_ciphers();
    OpenSSL_add_all_digests();
#ifndef OPENSSL_NO_ENGINE
    ENGINE_load_builtin_engines();
    ENGINE_register_all_complete();
#endif
#endif
#if defined(LIBSSH2_WOLFSSL) && defined(DEBUG_WOLFSSL)
    wolfSSL_Debugging_ON();
#endif
}