BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("Starting function BN_CTX_get()", ctx);
    
    if (ctx == NULL || ctx->err_stack || ctx->too_many) {
        return NULL;
    }

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("ErrorMessage: Too many temporary variables", ctx);
        return NULL;
    } 

    BN_zero(ret);

    if(ret->flags & BN_FLG_CONSTTIME) {
        ret->flags &= (~BN_FLG_CONSTTIME);
    }
   
   ctx->used = ctx->used + 1; 

    CTXDBG("Function BN_CTX_get() finished successfully", ctx);

    return ret;
}