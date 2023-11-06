BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get ():", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        ERR_raise(ERR_LIB_BN, BN_R_CTX_ERROR);
        return NULL;
    }
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    if (ctx->used < INT_MAX) ctx->used++;
    CTXDBG("COMPLETED BN_CTX_get ():", ctx);
    return ret;
}