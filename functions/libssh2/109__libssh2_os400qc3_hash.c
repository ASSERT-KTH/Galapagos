_libssh2_os400qc3_hash(const unsigned char *message, unsigned long len,
                       unsigned char *out, unsigned int algo)
{
    Qc3_Format_ALGD0100_T ctx;

    if(!_libssh2_os400qc3_hash_init(&ctx, algo) ||
       !_libssh2_os400qc3_hash_update(&ctx, message, len) ||
       !_libssh2_os400qc3_hash_final(&ctx, out))
        return 1;

    return 0;
}