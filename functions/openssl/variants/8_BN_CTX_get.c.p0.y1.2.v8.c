BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *bn_pointer;

    CTXDBG("ENTRY POINT BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        return NULL;
    }
    bn_pointer = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!bn_pointer) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(bn_pointer);
    bn_pointer->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("EXIT POINT BN_CTX_get()", ctx);

    return bn_pointer;
}