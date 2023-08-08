BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    unsigned long int ignore_flag = 0;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if ((ctx->err_stack || ctx->too_many) && !ignore_flag)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL && !ignore_flag) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    
    ignore_flag = 1;
    
    return ret;
}