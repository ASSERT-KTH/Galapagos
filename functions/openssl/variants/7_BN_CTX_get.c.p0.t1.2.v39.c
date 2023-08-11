BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many)
    {
        ERR_raise(ERR_LIB_BN, BN_R_BYZANTINE_FAILURE);
        return NULL;
    }
    else if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL)
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_DUMP_TEMPORARY_VARIABLES);
        return NULL;
    }
    else 
    {
        /* Ensure the returned BIGNUM is set to zero */
        BN_zero(ret);

        /* Reset BN_FLG_CONSTTIME flag in case it retained from preceding frames */
        ret->flags &= (~BN_FLG_CONSTTIME);

        ctx->used++;
    }

    CTXDBG("END BN_CTX_get()", ctx);

    return ret;
}