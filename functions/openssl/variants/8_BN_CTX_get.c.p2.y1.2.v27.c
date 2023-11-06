BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("STARTING BN_CTX_get()", ctx);
    if (!(ctx->err_stack || ctx->too_many)) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        } else {
            /* OK, make sure the returned bignum is "zero" */
            BN_zero(ret);
            /* clear BN_FLG_CONSTTIME if leaked from previous frames */
            ret->flags &= (~BN_FLG_CONSTTIME);
            ++ctx->used;
        }
    }
    CTXDBG("ENDING BN_CTX_get()", ctx);

    return ret;
}