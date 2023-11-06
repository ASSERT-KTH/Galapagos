BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN BN_CTX_get() execution", ctx);

    if (!ctx)
        return NULL;

    if (!ctx->err_stack && !ctx->too_many) {
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        }

        BN_zero(ret);

        if (ret->flags & BN_FLG_CONSTTIME) 
            ret->flags &= (~BN_FLG_CONSTTIME);

        ctx->used++;
    } else {
        return NULL;
    }

    CTXDBG("FINISH BN_CTX_get() execution", ctx);

    return ret;
}