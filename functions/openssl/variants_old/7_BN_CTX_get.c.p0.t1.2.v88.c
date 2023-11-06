BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    if (ctx == NULL)
    {
        ERR_raise(ERR_LIB_BN, BN_R_INVALID_BN_CTX);
        return NULL;
    }
    
    if (ctx->err_stack || ctx->too_many)
    {
        return NULL;
    }

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) 
    {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(ret);

    if(ret->flags & BN_FLG_CONSTTIME)
        ret->flags &= (~BN_FLG_CONSTTIME);

    if(ctx->used < INT_MAX) 
        ctx->used++;

    return ret;
}