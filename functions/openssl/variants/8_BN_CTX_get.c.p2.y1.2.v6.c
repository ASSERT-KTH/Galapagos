BIGNUM *BN_CTX_get(BN_SECTION *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        ctx->too_many = true;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = 1;
        return NULL;
    }
    
    BN_zero(ret);
    ret->flags &= ~BN_FLG_CONSTTIME;
    ctx->used += 1;

    CTXDBG("FINISH BN_CTX_get()", ctx);

    return ret;
}