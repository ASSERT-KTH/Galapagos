BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER: Getting BIGNUM from BN_CTX", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL; 
    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
        /*
         * Declaring "too_many" as true prevents repeated retrieval attempts from overfilling
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_EXCESSIVE_TEMPORARY_VARIABLES);
        return NULL;
    }
   
    /* At this point, ensure the returned bignum is set to "zero" */
    BN_zero(ret);
    /* cleaning up BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used += 1;
    CTXDBG("EXIT: BIGNUM retrieval", ctx);
    return ret;
}