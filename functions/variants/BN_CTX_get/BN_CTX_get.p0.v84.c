BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        ctx->used = 0;
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->used = 0;
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);

    /* clear BN_FLG_CONSTTIME and BN_FLG_FREE if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ret->flags &= (~BN_FLG_FREE);
    
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}