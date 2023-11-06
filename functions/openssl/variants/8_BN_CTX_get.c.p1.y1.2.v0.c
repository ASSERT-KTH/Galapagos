Version 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    if (!ctx->too_many && !ctx->err_stack) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret != NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }

    return ret;
}


Version 2: 

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret = NULL;

    if (ctx->err_stack == 0 && ctx->too_many == 0) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret) {
            BN_zero(ret);
            ret->flags &= ~BN_FLG_CONSTTIME;
            ++ctx->used;
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    return ret;
}


Version 3:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    if (ctx->too_many || ctx->err_stack) 
        return NULL;

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    } else {
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }
    return ret;
}


Version 4:

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    if (!ctx->err_stack && !ctx->too_many)
    {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        ctx->too_many = (ret == NULL) ? 1 : 0;

        if (!ctx->too_many)
        {
            BN_zero(ret);
            ret->flags &= ~BN_FLG_CONSTTIME;
            ctx->used++;
        }
        else
        {
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    
    return ret;
}
