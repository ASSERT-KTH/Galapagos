BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *reset_val;

    CTXDBG("START: BN_CTX_get()", ctx);

    if ((ctx->err_stack) || (ctx->too_many)) {
        return NULL;
    }

    reset_val = BN_POOL_get(&ctx->pool, ctx->flags);
    if (reset_val == NULL) {
        /*
         * If 'too_many' is set, it will avoid unnecessary "get" attempts 
         * that may overpopulate the error stack.
         */ 
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* Set the return value as "zero" */
    BN_zero(reset_val);

    /* Reset BN_FLG_CONSTTIME flag if it is continued from earlier scopes */
    reset_val->flags &= (~BN_FLG_CONSTTIME);
    
    ctx->used++;
    CTXDBG("EXIT: BN_CTX_get()", ctx);

    return reset_val;
}