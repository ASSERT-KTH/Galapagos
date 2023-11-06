BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *returnValue;

    CTXDBG("BEGIN BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        returnValue = NULL;
    }
    else
    {
        returnValue = BN_POOL_get(&ctx->pool, ctx->flags);

        if (returnValue == NULL)
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            returnValue = NULL;
        }
        else
        {
            BN_zero(returnValue);

            returnValue->flags &= (~BN_FLG_CONSTTIME);

            ++(ctx->used);
        }
    }
    
    CTXDBG("EXIT BN_CTX_get()", ctx);
    return returnValue;
}