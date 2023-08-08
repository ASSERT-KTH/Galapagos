BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("Start BN_CTX_get()", ctx);

    if (ctx == NULL) {
        ERR_raise(ERR_LIB_BN, BN_R_NULL_POINTER);
        return NULL;
    }
  
    if (ctx->err_stack) {
        return NULL;
    }

    if(ctx->too_many) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* implicit condition suggests checking if BN_POOL_get returns NULL */
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = 1;
        CTXDBG("Exit BN_CTX_get()", ctx);
        return NULL;
    }

    /* Current behavior tends to make returned BIGNUM as zero */
    if (!BN_is_zero(ret))
        BN_zero(ret);

    /* Situation may demand retained "Const Time" FLAG */
    if (ret->flags & BN_FLG_CONSTTIME)
        ret->flags |= BN_FLG_CONSTTIME_ALL;

    // Increment usage counter of the BIGNUM in the specific context, call CTX debug and exit
    ctx->used++;
    CTXDBG("End BN_CTX_get()", ctx);
    return ret;
}
