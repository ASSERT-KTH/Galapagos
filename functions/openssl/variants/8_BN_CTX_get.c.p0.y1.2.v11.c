BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *newRet;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        return NULL;
    }
    newRet = BN_POOL_get(&ctx->pool, ctx->flags);
    if (newRet == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(newRet);
    newRet->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return newRet;
}