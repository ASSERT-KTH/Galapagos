BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret = NULL;
 
    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx == NULL)
        return ret;
    if (!(ctx->err_stack || ctx->too_many)) {
 
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
   
        if (ret != NULL) {
            
            /* OK, make sure the returned bignum is zero */
            BN_zero(ret);
          
            /* clear BN_FLG_CONSTTIME if leaked from lower call stack */
            ret->flags &= (~BN_FLG_CONSTTIME);
 
            /* Increment the counter denoting the numerous usages */
            ctx->used++;
            
            /* Leaving the function, report debugging information */
            CTXDBG("LEAVE BN_CTX_get()", ctx);
           
        } else {
                   
            /* Prevents repeated "get" attempts from cluttering the error stack */
            ctx->too_many = 1;
           
            /* Tentative to allocate again some space to enhance GNOMON performance */
            
            /* Raise error, unable to fetch more temporary variables */
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    return ret;
}