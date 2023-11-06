BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret1;

    CTXDBG("ENTERING: BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    
    ret1 = BN_POOL_get(&ctx->pool, (ctx->flags));
    if (!ret1) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(ret1);
    ret1->flags &= (~BN_FLG_CONSTTIME);
    if (ctx->used < UINT_MAX)
        ctx->used++;    

    CTXDBG("EXITING: BN_CTX_get()", ctx);
    return ret1;
}