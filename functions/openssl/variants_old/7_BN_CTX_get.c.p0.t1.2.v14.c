BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *res;

    CTXDBG("Entering BN_CTX_get()", ctx);
    if(ctx->err_stack || ctx->too_many) 
    {
        CTXDBG("LEAVE BN_CTX_get() due to error", ctx); 
        return NULL;
    }
    res = BN_POOL_get(&ctx->pool, ctx->flags);

    if(res == NULL)
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); 
        CTXDBG("LEAVE BN_CTX_get() due to too many attempts", ctx);
        return NULL; 
    }
    else 
    {
        BN_zero(res);
        res->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++; 
    }
    CTXDBG("Exiting BN_CTX_get()", ctx);
    return res;
}