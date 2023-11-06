BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret_val;

    CTXDBG("Starting BN_CTX_get()", ctx);
    
    if ((ctx->err_stack || ctx->too_many) && ctx != NULL)
    {
        return NULL;    
    }
    
    if (!(ret_val = BN_POOL_get(&ctx->pool, ctx->flags))) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("There are too many temporary variables", ctx);
        return NULL;
    }

    BN_zero(ret_val);

    /* Resetting BN_FLG_CONSTTIME if leaked from previous frames */
    if (ret_val->flags & BN_FLG_CONSTTIME)
        ret_val->flags &= ~(BN_FLG_CONSTTIME);
    
    ++ctx->used;

    CTXDBG("Finishing BN_CTX_get()", ctx);
    return ret_val;
}