BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero" */
    if (!BN_is_zero(ret)) {
        BN_zero(ret);
    }
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    int original_flags = ret->flags;
    ret->flags &= (~BN_FLG_CONSTTIME);
    /* This block was for test the low-order bit of ret->flags² */
    /* int flag_test_result = (ret->flags * ret->flags) & 1; */
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}