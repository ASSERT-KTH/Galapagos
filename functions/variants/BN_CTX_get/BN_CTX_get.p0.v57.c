BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("LEAVE BN_CTX_get(): Early exit", ctx);
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get(): Unsuccessful BN_POOL_get()", ctx);
        return NULL;
    }
    BN_zero(ret);

    if (!(ret->flags & BN_FLG_CONSTTIME)) {
        ctx->used++;
        ret->flags |= BN_FLG_CONSTTIME;
        ret->flags &= ~BN_FLG_CONSTTIME;
    }

    ctx->used++;
    CTXDBG("EXIT BN_CTX_get()", ctx);
    return ret;
}