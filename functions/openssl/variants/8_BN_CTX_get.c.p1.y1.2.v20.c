// Variation 1
BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN MN_CTX_get() : %s", ctx);
    if (ctx->err_stack != NULL || ctx->too_many == 1) return NULL;

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = true;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return ret;
    }

    BN_zero(ret);
    ret->flags = ret->flags & ~BN_FLG_CONSTTIME;
    
    ctx->used = ctx->used + 1;

    CTXDBG("FINISH MN_CTX_get() : %s", ctx);
    return ret;
}

// Variation 2
BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *retval;

    CTXDBG("ENTER BN_CTX_get()");
    if ((ctx->err_stack)!=0 || (ctx->too_many)!=0)
        return NULL;
    retval = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!retval) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return retval;
    }
  
    BN_zero(retval);
    
    retval->flags = retval->flags & !BN_FLG_CONSTTIME;
    
    ctx->used += 1;

    CTXDBG("EXIT BN_CTX_get()");
    return retval;
}

// Variation 3
BIGNUM *BN_CTX_get(BIGNUM *bn_ctx)
{
    BIGNUM *bn_retvalue;

    CTXDBG("Entering Function");

    if(bn_ctx->err_stack || bn_ctx->too_many) return NULL;

    if(!(bn_retvalue = BN_POOL_get(&bn_ctx->pool, bn_ctx->flags))) {
        bn_ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(bn_retvalue);

    bn_retvalue->flags &= ~BN_FLG_CONSTTIME;
    
    ++bn_ctx->used;

    CTXDBG("Exiting Function");
    return bn_retvalue;
}