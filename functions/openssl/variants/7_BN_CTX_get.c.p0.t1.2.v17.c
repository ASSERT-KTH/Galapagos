BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTERED BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = 1; 
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("EXITING BN_CTX_get()", ctx);      
        return NULL;
    }
    /* clears BN integer and set it to zero */
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME); // remove BN_FLG_CONSTTIME flag if it set
    
    CTXDBG("INCREASING CTX USAGE", ctx);
    ctx->used++;

    CTXDBG("EXITING BN_CTX_get WITH SUCCESS", ctx);
    return ret;
}