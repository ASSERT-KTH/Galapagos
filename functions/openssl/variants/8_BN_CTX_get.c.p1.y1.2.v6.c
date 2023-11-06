Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx){
    BIGNUM *ret;
    CTXDBG("START BN_CTX_get()", ctx);

    if (!(ctx->err_stack) && !(ctx->too_many)) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret!= NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("EXIT BN_CTX_get()", ctx);
            return ret;
        }
    }

    ctx->too_many = 1;
    ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    CTXDBG("FAILS BN_CTX_get()", ctx);
    return NULL;
}

Variant 2:

BIGNUM *BN_CTX_get(BN_CTX *ctx){
    uint8_t errorHandler = 0;
    BIGNUM *ret;
    
    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    do{
        if(ctx->too_many || ctx->err_stack){
            errorHandler = 1;
            break;
        }
        
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (!ret) {
            errorHandler = 1;
            ctx->too_many = 1;
            break;
        }

        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    } while(0);

    if(errorHandler)
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return (errorHandler)?NULL:ret;
}

Variant 3:

BIGNUM *BN_CTX_get(BN_CTX *ctx){
    BIGNUM *ret;
    CTXDBG("ENTER BN_CTX_get()",ctx);

    if(ctx->err_stack || ctx->too_many)
        Err_Handle(ctx);
    else if((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL)
        Err_Handle(ctx);
    else{
        BN_zero(ret);
        ret -> flags &= (~BN_FLG_CONSTTIME);
        ctx -> used++;
    }

    CTXDBG("LEAVE BN_CTX_get()",ctx);
    return ctx->too_many ? NULL : ret;
}

void Err_Handle(BN_CTX *ctx){
    ctx -> too_many = 1;
    ERR_raise(ERR_LIB_BN,BN_R_TOO_MANY_TEMPORARY_VARIABLES);
}
