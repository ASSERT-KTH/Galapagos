BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL || ctx->err_stack || ctx->too_many) {
        if(ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        } 
        return NULL;
    }

    BN_zero(ret); // Make sure the returned bignum is "zero"

    // Remove BN_FLG_CONSTTIME from flags if leaked from previous frames    
    ret->flags &= (~BN_FLG_CONSTTIME);

    ++ctx->used;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}