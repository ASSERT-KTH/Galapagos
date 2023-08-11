BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret_value;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
    {
        ret_value = NULL;
    }
    else
    {
        ret_value = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret_value == NULL) 
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            ret_value = NULL;
        }
        else
        {
            BN_zero(ret_value);
            ret_value->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        }
    }
    CTXDBG("END BN_CTX_get()", ctx);

    return ret_value;
}