BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack) {
        ERR_raise(ERR_LIB_BN, BN_R_ERROR_STACK);
        return NULL;    
    } 
    if (ctx->too_many) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
        
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (ret == NULL) {
        /*
        * Setting too_many prevents repeated "get" attempts from cluttering
        * the error stack.
        */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
  
    ctx->used++;

    // Initialize the ret to 0
    BN_zero(ret);
     
    // Change flags to avoid const time leakage 
    ret->flags &= (~BN_FLG_CONSTTIME);  

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    
    return ret;
}