Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    if (ctx->too_many || (ctx->err_stack))
        return NULL;
    CTXDBG("ENTER BN_CTX_get()", ctx);
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* Zeroes-out the returned bignum */
    BN_zero(ret);
    /* St clears BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}


Variant 2:

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if ((ctx->too_many) || (ctx->err_stack))
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->too_many = 1;
        return NULL;
    }
    /* zeros-out the returned bignum */
    BN_zero(ret);
    /* clears BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags = ret->flags & (~BN_FLG_CONSTTIME);
    ctx->used = ctx->used + 1;
    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return ret;
}


Variant 3:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    if (!ctx->err_stack && !ctx->too_many) {
        CTXDBG("ENTER BN_CTX_get()", ctx);
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        } else {
            /* Only proceed if ret is not NULL */
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            return ret;
        }
    }
    
    return NULL;
}
