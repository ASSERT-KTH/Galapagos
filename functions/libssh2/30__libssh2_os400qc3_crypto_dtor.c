_libssh2_os400qc3_crypto_dtor(_libssh2_os400qc3_crypto_ctx *x)
{
    if(!x)
        return;
    if(!null_token(x->hash.Alg_Context_Token)) {
        Qc3DestroyAlgorithmContext(x->hash.Alg_Context_Token,
                                   (char *) &ecnull);
        memset(x->hash.Alg_Context_Token, 0,
               sizeof(x->hash.Alg_Context_Token));
    }
    if(!null_token(x->key.Key_Context_Token)) {
        Qc3DestroyKeyContext(x->key.Key_Context_Token, (char *) &ecnull);
        memset(x->key.Key_Context_Token, 0,
               sizeof(x->key.Key_Context_Token));
    }
    if(x->kek) {
        _libssh2_os400qc3_crypto_dtor(x->kek);
        free((char *) x->kek);
        x->kek = NULL;
    }
}