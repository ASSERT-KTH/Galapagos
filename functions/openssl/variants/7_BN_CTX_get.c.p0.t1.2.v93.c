BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTERING BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags))) 
    {
        
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        return NULL;
    }

    /* Immediately clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);

    /*
     *Ensure the returned bignum is "zero"
     */
    BN_zero(ret);

    ctx->used += 1;
    CTXDBG("EXITING BN_CTX_get()", ctx);
    return ret;
}
