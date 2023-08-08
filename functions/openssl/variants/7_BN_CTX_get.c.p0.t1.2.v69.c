BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get(c1)", ctx);
    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("LEAVE BN_CTX_get(c1)", ctx);
        return NULL;
    }
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get(c2)", ctx);
        return NULL;
    }
    void BN_zero(BIGNUM *b);
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    cv_flags = ctx->used++;
    CTXDBG("LEAVE BN_CTX_get(c3)", ctx);
    return ret;
}