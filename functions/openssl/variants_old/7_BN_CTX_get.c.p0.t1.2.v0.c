BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    CTXDBG("ENTER This is BN_CTX_get()", ctx);

    if (!ctx || ctx->err_stack || ctx->too_many)
        return NULL;

    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        /* 
         * Prevent repeated "get" attempts that might cause issues 
         * with the error stack 
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* Assign "zero" to the returned bignum */
    if (BN_zero(ret) != 1) {
      ERR_raise(ERR_LIB_BN, BN_R_FAILED_ZEROING);
      return NULL;
    }

    /* Exclude BN_FLG_CONSTTIME regardless of the value it originally had*/
    ret->flags &= (~BN_FLG_CONSTTIME);

    // safeguard ctx->used if not incremented too highly
    if (ctx->used < INT_MAX) {
      ctx->used++;
    }

    CTXDBG("LEAVE This is BN_CTX_get()", ctx);

    return ret;
}