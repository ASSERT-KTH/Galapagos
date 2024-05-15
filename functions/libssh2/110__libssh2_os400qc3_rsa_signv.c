_libssh2_os400qc3_rsa_signv(LIBSSH2_SESSION *session,
                            int algo,
                            unsigned char **signature,
                            size_t *signature_len,
                            int veccount,
                            const struct iovec vector[],
                            libssh2_rsa_ctx *ctx)
{
    Qus_EC_t errcode;
    Qc3_Format_ALGD0400_T algd;
    int siglen;
    unsigned char *sig;
    char sigbuf[8192];
    int sigbufsize = sizeof(sigbuf);

    algd.Public_Key_Alg = Qc3_RSA;
    algd.PKA_Block_Format = Qc3_PKCS1_01;
    memset(algd.Reserved, 0, sizeof(algd.Reserved));
    algd.Signing_Hash_Alg = algo;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CalculateSignature((char *) vector, &veccount, Qc3_Array,
                          (char *) &algd, Qc3_Alg_Public_Key,
                          (char *) &ctx->key, Qc3_Key_Token,
                          anycsp, NULL, sigbuf, &sigbufsize, &siglen,
                          (char *) &errcode);
    if(errcode.Bytes_Available)
        return -1;
    sig = LIBSSH2_ALLOC(session, siglen);
    if(!sig)
        return -1;
    memcpy((char *) sig, sigbuf, siglen);
    *signature = sig;
    *signature_len = siglen;
    return 0;
}