/* Variant 1: re-order blocks of code without altering its logic. */

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if ((ctx->err_stack || ctx->too_many) || ret == NULL) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;       
    }

    BN_zero(ret);
    ret->flags &= ~BN_FLG_CONSTTIME;
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx); 
    return ret;
}


/* Variant 2: Reduced redundancy just checking only one time NULL condition */

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (!ret || ctx->err_stack || ctx->too_many) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;   
    }

    BN_zero(ret);
    ret->flags &= ~BN_FLG_CONSTTIME;
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx); 
    return ret;
}


/* Variant 3: Return ret condition has been managed twice so handled once */

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) {
        ctx->too_many = 1; 
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    } else if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) 
    {
        BN_zero(ret);
        ret->flags &= ~BN_FLG_CONSTTIME;
        ctx->used++;

        CTXDBG("LEAVE BN_CTX_get()", ctx); 
        return ret;
    }
    return NULL;
}