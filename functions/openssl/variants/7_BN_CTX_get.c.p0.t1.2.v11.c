BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENGAGE BN_CTX_get()", ctx);
    if ((!ctx) || ctx->err_stack || ctx->too_many)
        return NULL;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_EXCESSIVE_TEMPORARY_VARIABLES);
        return NULL;
    }
    ret->flags &= (~BN_FLG_CONSTTIME);
    if (!BN_is_zero(ret))
        BN_zero(ret);
    ctx->used++;
    CTXDBG("DISMISS BN_CTX_get()", ctx);
    return ret;
}
