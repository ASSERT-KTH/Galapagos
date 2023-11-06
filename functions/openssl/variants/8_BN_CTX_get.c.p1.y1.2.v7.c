BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (!ctx->err_stack && !ctx->too_many) {
        
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }

    } 

    return ret;  
}

--------------------------------------------------------------------------------------------------------

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx);
    BIGNUM *ret = (ctx->err_stack || ctx->too_many) ? NULL : BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL && !ctx->err_stack && !ctx->too_many) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    } else if (ret != NULL) {
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }
  
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;  
}

--------------------------------------------------------------------------------------------------------

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many) {
        ctx->too_many = 0;
        ctx->used = 0;

        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret) {
            ctx->used++;
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    } else {
        ret = NULL;
    }

    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}