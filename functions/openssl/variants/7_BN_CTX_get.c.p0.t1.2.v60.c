BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTERING BN_CTX_get()", ctx);
    if (ctx->too_many || ctx->err_stack)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->too_many = 1;
        return NULL;
    }
    ret->flags &= (~(BN_FLG_CONSTTIME));
    /* OK, make sure the returned bignum is "zero"  and increment used count*/
    BSTACK_push(&ctx->used, ret);
    BN_zero(ret);
    CTXDBG(" EXIT BN_CTX_get()", ctx);
    return ret;
}