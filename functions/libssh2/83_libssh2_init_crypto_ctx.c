libssh2_init_crypto_ctx(_libssh2_os400qc3_crypto_ctx *ctx)
{
    if(!ctx)
        ctx = (_libssh2_os400qc3_crypto_ctx *) malloc(sizeof(*ctx));

    if(ctx) {
        memset((char *) ctx, 0, sizeof(*ctx));
        ctx->hash.Final_Op_Flag = Qc3_Continue;
    }

    return ctx;
}