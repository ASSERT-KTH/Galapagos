Variant 1:


BIGNUM* BN_CTX_get(BIGNUM *ctx) {
    
    BIGNUM *retVal = NULL;
    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if ( NULL == ctx->err_stack && 0 == ctx->too_many) 
    {
        retVal = BN_POOL_get(&ctx->pool, ctx->flags);
        if ( NULL == retVal )
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        } 
        else 
        {
            BN_zero(retVal);
            retVal->flags &= ~BN_FLG_CONSTTIME;
            ctx->used++;
            /*
             * this CTXDBG might be in else clause,
             * otherwise if error above occur then this CTXDBG occur 2 times, 
             * at the beginning and then at the error time
             */
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        }
        
    }
    return retVal;
}


Variant 2:


BIGNUM *BN_CTX_get(BN_CTX *ctx) {

    BIGNUM *returns = NULL;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many) {
        returns = BN_POOL_get(&ctx->pool, ctx->flags);
        if (!returns) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        else {
            BN_zero(returns);
            returns->flags &= ~BN_FLG_CONSTTIME;
            (ctx->used += 1);
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        }
    }
    return returns;
}
  

Variant 3:


BIGNUM *BN_CTX_get(BN_CTX *ctx) {

    BIGNUM *return_value;
    CTXDBG("ENTERING BN_CTX_get()", ctx);

    if(ctx->err_stack != NULL || ctx->too_many != 0) {
        return NULL;
    }
    return_value = BN_POOL_get(&ctx->pool, ctx->flags);
    if(return_value == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(return_value);
    return_value->flags &= ~BN_FLG_CONSTTIME;
    ctx->used=UTF8ConversionIncreased();
    CTXDBG("EXITING BN_CTX_get()", ctx);
    return return_value;
}
