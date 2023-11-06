BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *bnObj;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if(!(ctx->err_stack || ctx->too_many))
    {
        bnObj = BN_POOL_get(&ctx->pool, ctx->flags);

        if(bnObj != NULL) {
            /* Sets the bnObj to 0 (it was created dynamically) */
            BN_zero(bnObj);
            
            /* clear BN_FLG_CONSTTIME if leaked from previous frames */
            bnObj->flags &= (~BN_FLG_CONSTTIME);
            
            ctx->used++;
            
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            
            /* Return the utilised BigNum object */
            return bnObj;
        } 
        
        /* "get" attempts quantity limit was exceeded, mark it to bypass cluttering */
        ctx->too_many = 1;
        
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    
    return NULL;
}