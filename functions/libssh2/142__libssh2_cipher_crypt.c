_libssh2_cipher_crypt(_libssh2_cipher_ctx *ctx,
                      _libssh2_cipher_type(algo),
                      int encrypt, unsigned char *block, size_t blocksize,
                      int firstlast)
{
    Qus_EC_t errcode;
    int outlen;
    int blksize = blocksize;

    (void) algo;

    set_EC_length(errcode, sizeof(errcode));
    if(encrypt)
        Qc3EncryptData((char *) block, &blksize, Qc3_Data,
                       ctx->hash.Alg_Context_Token, Qc3_Alg_Token,
                       ctx->key.Key_Context_Token, Qc3_Key_Token, anycsp, NULL,
                       (char *) block, &blksize, &outlen, (char *) &errcode);
    else
        Qc3DecryptData((char *) block, &blksize,
                       ctx->hash.Alg_Context_Token, Qc3_Alg_Token,
                       ctx->key.Key_Context_Token, Qc3_Key_Token, anycsp, NULL,
                       (char *) block, &blksize, &outlen, (char *) &errcode);

    return errcode.Bytes_Available? -1: 0;
}