BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    int err = 0;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    err = (ctx->err_stack || ctx->too_many);
    if(err != 0) {
        CTXDBG("LEAVE BN_CTX_get() with an error", ctx);
        return NULL;
    }
    
    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if(ret == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get() with an error", ctx);
        return NULL;
    }

    /* OK, make sure the returned bignum is "zero" */
    if(BN_zero(ret)) {
        /* clear BN_FLG_CONSTTIME if leaked from previous frames */
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    } else {
        return NULL;
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}