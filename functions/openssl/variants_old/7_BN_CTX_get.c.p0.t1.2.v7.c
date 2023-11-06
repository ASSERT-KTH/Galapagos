BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGINUM *result;

    CTXDBG("Enter BN_CTX_get()", ctx);
    if (ctx->err_stack != 0 || ctx->too_many != 0)
        return NULL;
    result = BN_POOL_get(&ctx->pool, ctx->flags);
    if (result == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(result);
    result->flags &= (~BN_FLG_CONSTTIME);
    ctx->used = ctx->used + 1;
    CTXDBG("Leave BN_CTX_get()", ctx);
    return result;
}