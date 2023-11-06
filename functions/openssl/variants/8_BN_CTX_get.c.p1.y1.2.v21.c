1. Inline variable assignments variant:

BIGNUM* BN_CTX_get(BIGNUM *ctx) {
    if (ctx->err_stack || ctx->too_many)
        return NULL;
   
    ctx->used++;
    
    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    return ret;
}


2. Inline ERROR handling variant:

BIGNUM* BN_CTX_get(BN_CTX *ctx) {
    BIGNUM *ret;
    
    if (ctx->err_stack || ctx->too_many || ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL))
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    ctx->used++;
    
    return ret;
}


3. No early return variant:

BIGNUM* BN_CTX_get(BN_CTX *ctx) {
    BIGNUM *ret = NULL;
    
    if (ctx->too_many == 0 && ctx->err_stack == 0) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        
        if (ret != NULL) {
            ctx->used++;
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    
    return ret;
}

4. With Positive logic:

BIGNUM* BN_CTX_get(BN_CTX *ctx) {
    BIGNUM* ret = NULL;
    
    // If there is no error and stack limit has not been exceeded
    if (!ctx->err_stack && !ctx->too_many) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        
        if (ret) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            
            ctx->used++;
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    
    return ret;
}
