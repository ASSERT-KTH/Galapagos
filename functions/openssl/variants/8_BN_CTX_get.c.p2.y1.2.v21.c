BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG(">>> BEGIN BN_CTX_get()", ctx);
    
    if (ctx->err_stack) {
        return NULL;
    }
    
    if (ctx->too_many) {
        ctx->err_stack += 1;
        return NULL;
    }
    
    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(ret);

    if (ret->flags & BN_FLG_CONSTTIME)
    {
        ret->flags ^= BN_FLG_CONSTTIME;
    }

    ctx->used = ctx->used + 1;

    CTXDBG("<<< END BN_CTX_get()", ctx);

    return ret;
}