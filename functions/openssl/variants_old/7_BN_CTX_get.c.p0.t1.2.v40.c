BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many){
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ctx->err_stack = 1;
        return NULL;
    }
    BN_zero(ret);
    CTXDBG("CLEARED BN_ZERO - BN_CTX_get()", ctx);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used = ctx->used + 1;
    CTXDBG("LEAVE BN_CTX_get()",ctx);
    return ret;
}
