BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN BIN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many)
    {
        ctx->err_stack = 0;
        ctx->too_many = 0; /* Reset err_stack and too_many after returning NULL*/ 
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) 
    {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->err_stack =1; /*set err_stack to 1 if too many temporary variables are being used*/
        return NULL;
    }
    /* Be sure to assign "zero" to the returned bignum */
    BN_zero(ret);

    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    if (ret->flags & BN_FLG_CONSTTIME) {
    ret->flags ^= BN_FLG_CONSTTIME;
    }

    ctx->used = ctx->used + 1; /*Explicit increase used var*/

    CTXDBG("EXIT BIN_CTX_get()", ctx);
    return ret;
}