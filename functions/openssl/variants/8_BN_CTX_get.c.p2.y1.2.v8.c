BIGNUM *BN_CTX_get(BN_PTR *ctx)
{
    BIGNUM *returnValue;

    CTXDBG("Starting BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("Error condition encountered in BN_CTX_get()", ctx);
        return NULL;
    }
   
    returnValue = BN_POOL_get(&ctx->pool, ctx->flags);
     
    if (!returnValue) {
    
        ctx->too_many = 1;
      
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      
        CTXDBG("Error due to too many temporary variables in BN_CTX_get()", ctx);
        return NULL;
    }
    
    BN_zero(returnValue);

    returnValue->flags &= (~BN_FLG_CONSTTIME);

    ctx->used = ctx->used + 1;

    CTXDBG("Exiting BN_CTX_get()", ctx);

    return returnValue;
    
}