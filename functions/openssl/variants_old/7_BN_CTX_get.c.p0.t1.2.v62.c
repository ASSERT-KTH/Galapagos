BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        ctx->err_stack = 0;
        ctx->too_many = 0;
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(ret);

    if (ret->flags & BN_FLG_CONSTTIME) /* clear BN_FLG_CONSTTIME if leaked from previous frames */
        ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used += 1;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}