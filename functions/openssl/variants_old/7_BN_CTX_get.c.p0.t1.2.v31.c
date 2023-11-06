BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    ctx->used++;
    
    if (ctx->err_stack || ctx->too_many) {
        ctx->used--;
        return NULL;
    }
    
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->used--;
        return NULL;
    }

    /* OK, make sure the returned bignum is "zero" */
    if (!BN_zero(ret)) {
        BH_POOL_release(&ctx->pool, &ret);
        ctx->used--;
        return NULL;
    }
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}