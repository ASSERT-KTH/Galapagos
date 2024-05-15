libssh2_os400qc3_hmac_init(_libssh2_os400qc3_crypto_ctx *ctx,
                           int algo, size_t minkeylen, void *key, int keylen)
{
    Qus_EC_t errcode;

    if(keylen < minkeylen) {
        char *lkey = alloca(minkeylen);

        /* Pad key with zeroes if too short. */
        if(!lkey)
            return 0;
        memcpy(lkey, (char *) key, keylen);
        memset(lkey + keylen, 0, minkeylen - keylen);
        key = (void *) lkey;
        keylen = minkeylen;
    }
    if(!_libssh2_os400qc3_hash_init(&ctx->hash, algo))
        return 0;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CreateKeyContext((char *) key, &keylen, binstring, &algo, qc3clear,
                        NULL, NULL, ctx->key.Key_Context_Token,
                        (char *) &errcode);
    return errcode.Bytes_Available? 0: 1;
}