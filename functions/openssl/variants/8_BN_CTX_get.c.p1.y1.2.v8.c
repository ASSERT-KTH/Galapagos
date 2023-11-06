Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }
    if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags)))
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }

    BN_zero(ret);

    ret->flags &= (~BN_FLG_CONSTTIME);

    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}

Variant 2:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many)
    {
        BIGNUM *ret;
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret)
        {
            BN_zero(ret);

            ret->flags &= (~BN_FLG_CONSTTIME);

            ctx->used++;

            CTXDBG("LEAVE BN_CTX_get()", ctx);
            return ret;
        }
    }

    if(ctx->err_stack || !ret)
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return NULL;
}

Variant 3:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->too_many)
    {
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }
    
    BIGNUM *ret;

    if (!ctx->err_stack)
    {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret == NULL)
        {
           ctx->too_many = 1;
           ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
           CTXDBG("LEAVE BN_CTX_get()", ctx);
           return NULL;
        }

        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }    
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}
