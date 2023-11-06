// Variant 1: Single line returns
BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if ( (ctx->err_stack || ctx->too_many) || (ret == NULL) )  {
        if ( ret == NULL ) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }        

    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
   
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}

// Variant 2: Indexical bindings
BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    bool returnValueIsNull = (ctx->err_stack || ctx->too_many || (ret == NULL));

    if(returnValueIsNull) {
        if(ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }

    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}

// Variant 3: Linear execution
BIGNUM *BN_CTX_get(BN_CTX *ctx) 
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret != NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return ret;
}