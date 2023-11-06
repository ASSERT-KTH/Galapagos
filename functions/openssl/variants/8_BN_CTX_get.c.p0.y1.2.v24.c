BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *num;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack != NULL || ctx->too_many != 0)
        return NULL;
    num = BN_POOL_get(&ctx->pool, ctx->flags);

    if (num == NULL)
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    BN_zero(num);
    num->flags &= (~(BN_FLG_CONSTTIME));
    ctx->used = ctx->used + 1;
    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return num;
}