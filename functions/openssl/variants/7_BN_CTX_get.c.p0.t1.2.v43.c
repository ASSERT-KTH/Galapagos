BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    
    if(!ctx)
        return NULL;
    
    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    /* A bit different approach: Check and set the "too_many" flag before doing anything else */
    if (ctx->too_many) {
        return NULL;
    }
    
    /* Only check for error stack after checking for "too_many" flag */
    if(ctx->err_stack){
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
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
    
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret; 
}
