static void _libssh2_sha_algo_value_hash(int sha_algo,
                                         LIBSSH2_SESSION *session,
                                         kmdhgGPshakex_state_t *exchange_state,
                                         unsigned char **data, size_t data_len,
                                         const unsigned char *version)
{
    if(sha_algo == 512) {
        LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(512, *data, data_len, version);
    }
    else if(sha_algo == 384) {
        LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(384, *data, data_len, version);
    }
    else if(sha_algo == 256) {
        LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(256, *data, data_len, version);
    }
    else if(sha_algo == 1) {
        LIBSSH2_KEX_METHOD_SHA_VALUE_HASH(1, *data, data_len, version);
    }
    else {
#ifdef LIBSSH2DEBUG
        assert(0);
#endif
    }
}