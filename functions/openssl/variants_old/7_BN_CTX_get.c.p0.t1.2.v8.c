BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGINNING BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;    
    }
    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) 
    {
        /* Stop repeated "get" attempts from filling up the error stack */
        ctx->too_many = 1;
        CTXDBG("END BN_CTX_get()", ctx); // Moved to here from where it was to show ending point, but does the same function overall
        return NULL;
    }

    BN_zero(ret); // ensuring that our BIGNUM object equals zero
    ret->flags &= ~BN_FLG_CONSTTIME; // Making sure BN_FLG_CONSTTIME is clear whether it comes from earlier uses or not
    ctx->used++;

    CTXDBG("FINALIZATION BN_CTX_get()", ctx); // Changed debug message and moved it from close to return statement
    return ret;
}