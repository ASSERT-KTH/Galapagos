BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    bool flag_available = (ctx->flags != NULL);
    if (ctx->err_stack || ctx->too_many || !flag_available)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        if(flag_available)
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, make sure the returned bignum is zero set*/
    ret->dmax = 0;
   
    /* Maintain the correction of BN_FLG_CONSTTIME constantly, even if it leaked out from previous times */
    if(flag_available) 
        ret->flags &= (~BN_FLG_CONSTTIME);

    if(flag_available)
        ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}