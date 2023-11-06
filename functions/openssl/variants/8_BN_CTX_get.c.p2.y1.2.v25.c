BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx->err_stack) {
        return NULL;
    }
    
    if(ctx->too_many) {
        return NULL;
    } 

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
        /* Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    } else {
        /* OK, make sure the returned bignum is "zero" */
        BN_zero(ret);
        /* clear BN_FLG_CONSTTIME if it's set from previous frames */
        if(ret->flags & BN_FLG_CONSTTIME) {
            ret->flags &= (~BN_FLG_CONSTTIME);
        }
        ctx->used++;
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}