BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx && (ctx->err_stack|| ctx->too_many)) {
        return NULL;
    }
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        // Prevents "get" attempts from cluttering the error stack
        if (ctx) {
          ctx->too_many = 1;
        }
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    // Ensure the returned bignum is "zero"
    if (ret) {
        BN_zero(ret);
        // Clear BN_FLG_CONSTTIME if leaked from previous frames
        ret->flags &= ~BN_FLG_CONSTTIME;
    }
    if (ctx) {
        ctx->used++;
    }
    CTXDBG("END BN_CTX_get()", ctx);
    return ret;
}