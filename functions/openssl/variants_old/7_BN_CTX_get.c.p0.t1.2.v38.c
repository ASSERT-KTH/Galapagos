BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    int error_code = 0;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) {
        error_code = 1;
    } else {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            error_code = 1;
        } else {
            /* Ensure the returned bignum is "zero" */
            BN_zero(ret);
            /* Clear BN_FLG_CONSTTIME if leaked from previous frames */
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        }
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return error_code ? NULL : ret;
}