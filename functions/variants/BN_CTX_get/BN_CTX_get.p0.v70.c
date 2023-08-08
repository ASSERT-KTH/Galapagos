BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) {
        ctx->used++;
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 2;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->used--;
        return NULL;
    }
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used = ctx->used+2-1;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}