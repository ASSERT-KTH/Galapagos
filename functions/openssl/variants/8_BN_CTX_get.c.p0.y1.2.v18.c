BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *tmp_bignum;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx->err_stack || ctx->too_many)
    {
        return NULL;
    }

    tmp_bignum = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (!tmp_bignum) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    BN_zero(tmp_bignum);

    tmp_bignum->flags &= (~BN_FLG_CONSTTIME);

    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return tmp_bignum;
}