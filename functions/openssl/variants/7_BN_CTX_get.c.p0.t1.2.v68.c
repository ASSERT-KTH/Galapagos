BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) 
    {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->too_many = 1;
        return NULL;
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_NULL_POINTER);
        return NULL;
    }

    /* Clear fields of the returned BIGNUM */
    BN_zero(ret);
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    ctx->used++;
    CTXDBG("FINISH BN_CTX_get()", ctx);

    return ret;
}