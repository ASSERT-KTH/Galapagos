BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /* Setting 'too_many' to 1 */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }
    /* New scope to concentrate the flags modifications */
    {
        /* OK, make sure the returned bignum is "zero" */
        BN_zero(ret);
 
        /* remove 'BN_FLG_CONSTTIME' flag */
        ret->flags &= (~BN_FLG_CONSTTIME);
    }
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}