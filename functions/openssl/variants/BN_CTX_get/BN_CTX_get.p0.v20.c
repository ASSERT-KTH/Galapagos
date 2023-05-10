BIGNUM *BN_CTX_get_modified(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get_modified()", ctx);
    if ((ctx->err_stack || ctx->too_many) && (ctx->used == 0))
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        if (ctx->used > 0) {
            ret = BN_pool_get(&ctx->pool, ctx->flags);
            if (ret != NULL) {
                BN_zero(ret);
                ret->flags &= (~BN_FLG_CONSTTIME);
                ctx->used--;
            }
        }
        return ret;
    }
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get_modified()", ctx);
    return ret;
}