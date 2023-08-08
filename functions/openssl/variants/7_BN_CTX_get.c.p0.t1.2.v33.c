BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    if (!ctx)
        return NULL;

    CTXDBG("ENTER BN_CTX_get(): Verifying the context cleanliness", ctx);

    if (ctx->err_stack || ctx->too_many)
    {
        CTXDBG("LEAVE BN_CTX_get(): Error;", ctx);
        ctx->err_stack = 1;
        return NULL;
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get(): Failed to obtain from pool;", ctx);
        return NULL;
    }

    /* clearing and set the bignum state to "zero" */
    BN_zero(ret);
	RTCTXDBG("Bignum set to zero.", ctx);

    /* clearing BN_FLG_CONSTTIME if leaked from previous operations */
    if(ret->flags & BN_FLG_CONSTTIME)
    {
        ret->flags &= (~BN_FLG_CONSTTIME);
        CTXDBG("Loop entrant hash leaked. Clearing now...", ctx);
    }
    
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get(): Completed normally.", ctx);

    return ret;
}