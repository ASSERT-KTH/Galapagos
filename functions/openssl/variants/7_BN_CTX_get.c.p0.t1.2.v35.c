BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        
        ctx->too_many = 1;
        if (ctx->err_stack || ctx->too_many)
            return NULL;
        
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    /* OK, clear BN_FLG_CONSTTIME if it has leaked from the previous frames */  
    ctx->used++; 

    ret->flags &= (~BN_FLG_CONSTTIME); 
    
    /* Make sure the returned bignum is "zero" */
    BN_zero(ret);
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}