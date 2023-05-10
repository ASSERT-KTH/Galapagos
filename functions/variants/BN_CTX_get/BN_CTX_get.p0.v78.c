BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx->err_stack)
        return NULL;
    
    if (ctx->too_many) {
        ctx->too_many = 0;
        return NULL;
    }
    
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    /* OK, make sure the returned bignum is "zero" by calling the alternative function directly */
    BN_set_word(ret, 0);
    
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    /* increment ctx->used value */
    ctx->used += 1;
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    
    return ret;
}