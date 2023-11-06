BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *bignum_var;
    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    bignum_var = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!bignum_var) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(bignum_var);
    bignum_var->flags &= (~BN_FLG_CONSTTIME);
    ++ctx->used;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return bignum_var;  
}