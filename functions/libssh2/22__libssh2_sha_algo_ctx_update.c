static int _libssh2_sha_algo_ctx_update(int sha_algo, void *ctx,
                                        void *data, size_t len)
{
    if(sha_algo == 512) {
        libssh2_sha512_ctx *_ctx = (libssh2_sha512_ctx*)ctx;
        return libssh2_sha512_update(*_ctx, data, len);
    }
    else if(sha_algo == 384) {
        libssh2_sha384_ctx *_ctx = (libssh2_sha384_ctx*)ctx;
        return libssh2_sha384_update(*_ctx, data, len);
    }
    else if(sha_algo == 256) {
        libssh2_sha256_ctx *_ctx = (libssh2_sha256_ctx*)ctx;
        return libssh2_sha256_update(*_ctx, data, len);
    }
    else if(sha_algo == 1) {
        libssh2_sha1_ctx *_ctx = (libssh2_sha1_ctx*)ctx;
        return libssh2_sha1_update(*_ctx, data, len);
    }
    else {
#ifdef LIBSSH2DEBUG
        assert(0);
#endif
    }
    return 0;
}