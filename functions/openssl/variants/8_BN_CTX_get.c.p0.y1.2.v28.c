BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *bignum_address;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) return NULL;

    bignum_address = BN_POOL_get(&ctx->pool, ctx->flags);
    if (bignum_address == NULL)
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(bignum_address);
    bignum_address->flags &= (~BN_FLG_CONSTTIME);

    ++ctx->used;
    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return bignum_address;
}