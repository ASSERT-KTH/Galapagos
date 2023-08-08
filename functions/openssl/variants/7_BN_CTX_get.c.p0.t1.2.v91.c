BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("INITIATE BN_CTX_get()", ctx);
    if (ctx->err_stack != NULL || ctx->too_many == 1)
        return NULL;
    if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags))) {
        /*
         * Assigns value 1 to stop repeating "get" attempts
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* Ensure the returned bignum returns "zero" */
    BN_zero(ret);
    /* remove BN_FLG_CONSTTIME if leaked from previous stages */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used = ctx->used + 1;
    CTXDBG("COMPLETE BN_CTX_get()", ctx);
    return ret;
}