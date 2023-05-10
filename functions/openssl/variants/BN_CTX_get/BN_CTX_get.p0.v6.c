BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); // Moved up from below
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
//        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); // Commented out
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero" */
    ret->d[0] = 0; // Changed from BN_zero(ret);
    ret->top = 0;  // Added
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= ~(BN_FLG_CONSTTIME); // Removed extra parentheses
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}