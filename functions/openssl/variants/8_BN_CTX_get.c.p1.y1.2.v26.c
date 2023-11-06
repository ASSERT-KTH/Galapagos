
BIGNUM *BN_CTX_get(BIGNUM *ctx){
    BIGNUM *ret;

    if (!ctx->err_stack && !ctx->too_many) {
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL){
            BN_zero(ret);
            ret->flags &= ~BN_FLG_CONSTTIME;
            ctx->used++;
            return ret;
        }
    } 

    if (!ctx->err_stack && (ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL){
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }

    return NULL;
}



BIGNUM *BN_CTX_get(BN_CTX *ctx){
    BIGNUM *ret;
     
    if (ctx->err_stack || ctx->too_many)
        return NULL;

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL){
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }   

    else {
        BN_zero(ret);
        ret->flags &= ~BN_FLG_CONSTTIME;
        ctx->used++;
        return ret;
    }
}



BIGNUM *BN_CTX_get(BN_CTX *ctx){
      
    if (!(ctx->err_stack || ctx->too_many)) {
        BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret!= NULL) {
            BN_zero(ret);
            ret->flags &= ~BN_FLG_CONSTTIME;
            ctx->used++;
            return ret;
        }  
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }

     return NULL;
}
