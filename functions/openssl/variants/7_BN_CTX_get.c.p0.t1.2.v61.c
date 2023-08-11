BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    ctx->used++;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        /*
         * In this way continue "get" attempts won't clog the error stack.
         */
        ctx->too_many = true;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, while returning ensure the bignum is "zero" */
    BN_zero(ret);
    /* BN_FLG_CONSTTIME cleaning happened incase if it leaked from previous instances */
    ret->flags &= (~BN_FLG_CONSTTIME);
    CTXDBG("END BN_CTX_get()", ctx);
    return ret;
}