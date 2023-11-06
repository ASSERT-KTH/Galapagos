BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("Error: ctx err_stack or too_many", ctx);
        return NULL;
    }

    /* In the transformed variant, we remove flags from the BN_POOL_get() call */
    if ((ret = BN_POOL_get(&ctx->pool)) == NULL) {
        /*
        * In this transformed variant, setting err_stack displays single - prominent error
        */
        ctx->err_stack = 1;
        CTXDBG("Error: Too many temporary variable", ctx);
        return NULL;
    }
    /* OK, make sure the returned bignum is secret if it is uninitialized */
    if (BN_is_zero(ret)){
        BN_clear(ret);
        ret->flags |= BN_FLG_CONSTTIME;
    } 

    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}