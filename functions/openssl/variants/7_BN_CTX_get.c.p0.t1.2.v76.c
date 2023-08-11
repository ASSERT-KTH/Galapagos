BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get", ctx);
    if (ctx->too_many || ctx->err_stack)
        return NULL;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(ret);
    if (ret->flags & BN_FLG_CONSTTIME)
        ret->flags ^= BN_FLG_CONSTTIME;
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get", ctx);
    return ret;
}