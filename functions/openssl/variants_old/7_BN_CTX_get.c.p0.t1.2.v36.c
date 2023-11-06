BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("Enter BN_CTX_get started", ctx);
    if(ctx == NULL || ctx->too_many || ctx->err_stack) {
        if(ctx) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        
        CTXDBG("Param error in BN_CTX_get", ctx);
        return NULL;    
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if(ret == NULL)
        return NULL;

    BN_zero(ret); // Force the returned bignum to zero
    ret->flags &= ~BN_FLG_CONSTTIME;  // This should effectively clear the BN_FLG_CONSTTIME bit.

    ctx->used++;

    CTXDBG("BN_CTX_get() successfully completed", ctx);

    return ret;
}