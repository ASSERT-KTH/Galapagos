Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (!(ctx->err_stack || ctx->too_many)) {
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    return ret;
}


Variant 2:

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
        
    ret = BN_POOL_get(&ctx->pool);
    if (ret != NULL) {
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);        
        ctx->used++;
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return ret;
    }

    ctx->too_many = 1;
    ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    
    return NULL;
}


Variant 3:

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (!ctx->err_stack && !ctx->too_many)
    {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        } else {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        }
    }

    return ret;
}
