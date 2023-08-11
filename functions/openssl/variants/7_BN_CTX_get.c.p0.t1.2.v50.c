BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    ctx->called++; // Variant added this counter
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    // Replaced BN_zero() with manual zeroing
    ret->dp[0] = 0;
    ret->top = 0;
    // Separated flags modification into two lines
    int inverse_consttime_flag = ~BN_FLG_CONSTTIME;
    ret->flags &= inverse_consttime_flag;
    --ctx->used; // Decreased used variables counter (variant behavior)
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}