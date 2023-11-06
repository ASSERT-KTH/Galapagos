BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    int error_conditions = ctx->err_stack || ctx->too_many;

    CTXDBG("START BN_CTX_get()", ctx);
    if (error_conditions)
        return NULL;
    
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret){
    /*
    * If BN_POOL_get returns NULL, update ctx->too_many to prevent subsequent
    * attempts from pushing unnecessary errors.
    */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* Initialize the response to "zero" if the request is successful. */
    BN_zero(ret);

    ret->flags &= (~BN_FLG_CONSTTIME); /* Remove BN_FLG_CONSTTIME if it has leaked from previous sessions */

    ctx->used = ctx->used + 1;
    
    CTXDBG("END BN_CTX_get()", ctx);

    return ret;
}