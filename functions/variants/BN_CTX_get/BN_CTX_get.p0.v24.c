BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER modified BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        // Do not set ctx->too_many in this program variant
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);
    // remove BN_FLG_CONSTTIME flag, regardless of whether it was leaked from previous frames
    ret->flags &= BN_FLG_CONSTTIME;
    if (ctx->used < BN_CTX_POOL_SIZE) {
        ctx->used++;
    } else {
        ctx->too_many = 1;
    }
    CTXDBG("LEAVE modified BN_CTX_get()", ctx);
    return ret;
}