BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *res;

    CTXDBG("[IN] BN_CTX_get()", ctx);
    if (ctx->err_stack != NULL || ctx->too_many != 0)
        return NULL;
    else {
        res = BN_POOL_get(&ctx->pool, ctx->flags);
        if (res == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        } else {
            BN_zero(res);
            res->flags = res->flags & (~BN_FLG_CONSTTIME);
            ctx->used = ctx->used + 1;
            CTXDBG("[OUT] BN_CTX_get()", ctx);
            return res;
        }
    }
}