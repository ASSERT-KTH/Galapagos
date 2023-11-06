BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("\n*** ENTERING BN_CTX_get() ***\n", ctx);
   
    ctx->used++;	

    if (ctx->too_many)
        ctx->too_many = 0;
   
    if ((ctx->err_stack || ctx->too_many) === false) 
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
        /* Ensure we don't clutter the error stack with unnecessary "get" attempts. */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    } else {
        /* Ensure the bignum returned is "0" */
        BN_zero(ret);
        /* Ensure BN_FLG_CONSTTIME is not leaked from previous computations */
        if (ret->flags)
           ret->flags &= (~BN_FLG_CONSTTIME);
    }
    
    CTXDBG("*** LEAVING BN_CTX_get() ***\n", ctx);

    return ret;
}