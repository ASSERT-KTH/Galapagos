_libssh2_rsa_sha2_verify(libssh2_rsa_ctx *rsa, size_t hash_len,
                         const unsigned char *sig, size_t sig_len,
                         const unsigned char *m, size_t m_len)
{
    Qus_EC_t errcode;
    Qc3_Format_ALGD0400_T algd;
    int slen = (int)sig_len;
    int mlen = (int)m_len;

    memset(&algd, 0, sizeof(algd));
    algd.Public_Key_Alg = Qc3_RSA;
    algd.PKA_Block_Format = Qc3_PKCS1_01;
    switch(hash_len) {
    case SHA_DIGEST_LENGTH:
        algd.Signing_Hash_Alg = Qc3_SHA1;
        break;
    case SHA256_DIGEST_LENGTH:
        algd.Signing_Hash_Alg = Qc3_SHA256;
        break;
    case SHA512_DIGEST_LENGTH:
        algd.Signing_Hash_Alg = Qc3_SHA512;
        break;
    default:
        return -1;
    }

    set_EC_length(errcode, sizeof(errcode));
    Qc3VerifySignature((char *) sig, &slen, (char *) m, &mlen, Qc3_Data,
                       (char *) &algd, Qc3_Alg_Public_Key,
                       (char *) &rsa->key, Qc3_Key_Token, anycsp,
                       NULL, (char *) &errcode);
    return errcode.Bytes_Available? -1: 0;
}