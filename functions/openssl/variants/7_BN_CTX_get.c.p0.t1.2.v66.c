BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }
    /* OK, checks and sets the returned bignum to "zero" before going further */
    if(!BN_is_zero(ret)) {
        BN_zero(ret);
    }
    /* clear BN_FLG_CONSTTIME if it is still set from previous frames */
    if (ret->flags & BN_FLG_CONSTTIME) {
        ret->flags &= (~BN_FLG_CONSTTIME);
    }
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}