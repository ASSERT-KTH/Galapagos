BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);
    
    int errCondition = ctx->err_stack || ctx->too_many;
    if (errCondition)
        return NULL;
    
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = errCondition = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    BN_zero(ret);
    ret->flags = ret->flags & (~BN_FLG_CONSTTIME);
 
    /* increment used */
    ++ctx->used;

    CTXDBG("END BN_CTX_get()", ctx);
    
    return ret;
}