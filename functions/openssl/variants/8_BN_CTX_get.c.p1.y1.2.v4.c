Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *outcome;
    CTXDBG("BN_CTX_get() ENTERED", ctx);
    if(ctx->err_stack || ctx->too_many)
        return NULL;
    
    outcome = BN_POOL_get(&ctx->pool,ctx->flags);
    if (outcome == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(outcome);
    outcome->flags ^= outcome->flags & BN_FLG_CONSTTIME;
    ++ctx->used;
    CTXDBG("BN_CTX_get() EXISTED", ctx);
    return outcome;
}


Variant 2:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *returnedValue;
    CTXDBG(" Going Inside BN_CTX_get()", ctx);
    if(ctx->too_many || ctx->err_stack)
        return NULL;
    
    returnedValue = BN_POOL_get(&ctx->pool, ctx->flags);
    if (returnedValue == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    returnedValue->flags = returnedValue->flags & (-BN_FLG_CONSTTIME - 1);
    BN_zero(returnedValue);
    ++ctx->used;
    CTXDBG(" Going out BN_CTX_get()", ctx);
    return returnedValue;
}
