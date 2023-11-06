BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx == NULL)
        return NULL;
        
    if (ctx->err_stack)
    {
        ctx->err_stack = 0;
        return NULL;
    }
    if (ctx->too_many)
    {
        ctx->too_many = 0;
        return NULL;
    }
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (ret == NULL)
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    else
    {
        BN_zero(ret);
        /* clear BN_FLG_CONSTTIME if leaked from previous frames, only if not already cleared */
        if (ret->flags & BN_FLG_CONSTTIME)
            ret->flags &= (~BN_FLG_CONSTTIME);
    
        if (ctx->used < INT_MAX)
            ctx->used++;
    }
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}