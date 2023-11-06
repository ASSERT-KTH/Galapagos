BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->too_many || ctx->err_stack) {
        return NULL;
    } else {
        BIGNUM *result = BN_POOL_get(&ctx->pool, ctx->flags);
        if (result == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        } else {
            /* Make sure the given bignum is "zero" */
            BN_zero(result);
            /* Clear BN_FLG_CONSTTIME if leaked from previous frames */
            result->flags &= ~BN_FLG_CONSTTIME;
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            return result;
        }
    }
}