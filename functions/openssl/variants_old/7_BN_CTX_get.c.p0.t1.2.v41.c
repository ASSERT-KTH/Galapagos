BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    
    if (ctx == NULL) {
        return NULL;
    }

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx->err_stack || ctx->too_many)
        return NULL;
        
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    
    BN_zero(ret); // Move this after used++ 

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}