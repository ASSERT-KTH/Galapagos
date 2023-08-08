BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    if (ctx->err_stack || ctx->too_many)
        return NULL;

    /* We keep the initialized state of the returned BIGNUM as is */
    /* BN_zero(ret); */

    ret->flags &= (!BN_FLG_CONSTTIME);

    /* If BIGNUM was obtained successfully increment used counter */
    if (!(ctx->err_stack || ctx->too_many)){
        ctx->used++;
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}