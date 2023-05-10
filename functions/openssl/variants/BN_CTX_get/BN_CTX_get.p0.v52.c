BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("LEAVE BN_CTX_get() with NULL", ctx);
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get() with failure", ctx);
        return NULL;
    }
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    if (ctx->used >= ctx->max) {
        ctx->err_stack = 1;
        ERR_raise(ERR_LIB_BN, BN_R_MAXIMUM_STACK_SIZE_EXCEEDED);
    }
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}