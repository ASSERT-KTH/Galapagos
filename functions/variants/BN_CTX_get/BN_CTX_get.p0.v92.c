BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    int success;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    success = (ret != NULL);
    if (!success) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ret = NULL;
    } else {
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}