// swapping the code inside the conditionals 
BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);    

    if (!(ctx->err_stack || ctx->too_many)) {
        
        if (!((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL)) {
            
            BN_zero(ret); 
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;    
        } else {
            
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        } 
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return ret;
    }
    return NULL;
} 

// Reordering the lines of the code 
BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx); 

    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ctx->err_stack || ctx->too_many || !ret) {

        if(!ret){
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        return NULL;
    } 

    if (ret) {
        
        BN_zero(ret); 
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;  
        
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return ret;
    }
    return NULL;
} 

// Mixing conditions into if statements
BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx); 

    if (ctx->err_stack || ctx->too_many) 
        return NULL;

    if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags))) {
        
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;        
    } else {
        
        BN_zero(ret); 
        ret->flags &= (~BN_FLG_CONSTTIME);  
        ctx->used++;      
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}