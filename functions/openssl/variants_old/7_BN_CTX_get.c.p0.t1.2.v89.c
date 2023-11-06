BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("CALL BN_CTX_get()", ctx);
    if (ctx->too_many || ctx->err_stack)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_EXCESSIVE_TEMP_VARIABLES);
        return NULL;
    }
    BN_zero(ret);
    ret->flags &= ~(BN_FLG_CONSTTIME);
    ctx->used = ctx->used + 1;
    CTXDBG("EXIT BN_CTX_get()", ctx);
    return ret;
}