Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get", ctx);

    if (!ctx->err_stack && !ctx->too_many)
    {
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("END BN_CTX_get", ctx);
            return ret;
        }
    }

    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }

   return NULL;
}


Variant 2:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret=NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many)
    {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret!=NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        }
        else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    return ret;
}


Variant 3:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if(ctx->err_stack == 0 && ctx->too_many == 0)
    {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if(ret)
            {
            BN_zero(ret);
            ret->flags &= ~BN_FLG_CONSTTIME;
            ctx->used++;
            }
        else
            {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            }
    }
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}
