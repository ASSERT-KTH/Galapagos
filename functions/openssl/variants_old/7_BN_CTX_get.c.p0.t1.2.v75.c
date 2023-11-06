BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *retval;

    CTXDBG("START BN_CTX_get()", ctx);
    if ((ctx->err_stack != NULL) || (ctx->too_many))
        return NULL;
    retval = BN_POOL_get(&ctx->pool, ctx->flags);
    if (retval == NULL) {
        /*
         * Avoid filling the error stack by repeated attempts to "get".
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* Let's make sure the return bignum is zero */
    BN_zero(retval);
    /* Leak from previous frames? Clear away BN_FLG_CONSTTIME */
    retval->flags &= ~BN_FLG_CONSTTIME;
    ctx->used++;
    CTXDBG("COMPLETE BN_CTX_get()", ctx);
    return retval;
}