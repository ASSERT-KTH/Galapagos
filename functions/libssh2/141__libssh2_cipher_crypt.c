_libssh2_cipher_crypt(_libssh2_cipher_ctx * ctx,
                      _libssh2_cipher_type(algo),
                      int encrypt, unsigned char *block, size_t blklen,
                      int firstlast)
{
    int ret;

    (void)algo;
    (void)firstlast;

    if(encrypt) {
        ret = gcry_cipher_encrypt(*ctx, block, blklen, block, blklen);
    }
    else {
        ret = gcry_cipher_decrypt(*ctx, block, blklen, block, blklen);
    }
    return ret;
}