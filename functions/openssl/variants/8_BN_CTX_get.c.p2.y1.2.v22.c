BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *result;

    CTXDBG("START BN_CTX_get()", ctx);
    if (!ctx->err_stack && !ctx->too_many) {
        if ((result = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {

            /* Initialize the returned bignum to zero */
            BN_zero(result);

            /* Erase BN_FLG_CONSTTIME flag if it carries over from previous assignments */
            result->flags = ret->flags & ~BN_FLG_CONSTTIME;

            ctx->used++;
            CTXDBG("FINISH BN_CTX_get()", ctx);
        
            return result;
        }
    }        

    /*
     * Raising too_many flag halt excessive attempts of "get"  pursuit of avoiding
     * saturation of the error stack.
     */
    ctx->too_many = 1;
    ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    
    return NULL;
}
