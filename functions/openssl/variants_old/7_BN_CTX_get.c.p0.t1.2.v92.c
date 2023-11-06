BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret_val;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
         ERR_raise(ERR_LIB_BN, BN_R_STACK_ERROR);
        return NULL;
    }
    if ((ret_val = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ERR_raise(ERR_LIB_BN, BN_R_NO_BIGNUM_RET_VAL);
        return NULL;
     }
     
    /* Ok, Let's make sure the returned bignum is "empty" */
    BN_zero(ret_val);
     /* If ret_fun's BN_FLG_CONSTTIME is set, let's unset it. */
    ret_val->flags &= (~BN_FLG_CONSTTIME);
    
    /* Increase ctx usage tracker by one. */
    ctx->used = ctx->used + 1;
    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return ret_val;
}