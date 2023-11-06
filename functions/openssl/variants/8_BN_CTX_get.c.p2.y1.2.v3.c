BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTERING FUNCTION BN_CTX_get()", ctx);
    
    if ((ctx->err_stack || ctx->too_many)) {
        CTXDBG("CONTEXT ERROR OR TOO MANY VARIABLES", ctx);
        return NULL;
    }

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
        /* OK, make sure the returned bignum is "zero" */
        BN_zero(ret);
        /* clear BN_FLG_CONSTTIME if needed */
        if (ret->flags & BN_FLG_CONSTTIME)
            ret->flags ^= BN_FLG_CONSTTIME;
        ctx->used++;
        CTXDBG("LEAVING FUNCTION BN_CTX_get()", ctx);
        return ret;
    } else {
        /*
         * Prevents further "get" calls making error stack dirty.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("ERROR! TOO MANY TEMPORARY VARIABLES", ctx);
        return NULL;
    }
    
}
