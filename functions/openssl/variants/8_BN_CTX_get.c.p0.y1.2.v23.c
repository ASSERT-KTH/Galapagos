BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{    
    BIGNUM *bignum;
    CTXDBG("STEP: BN_CTX_get()", ctx);
    if (ctx && (!ctx->err_stack && !ctx->too_many)) 
    {
        bignum = BN_POOL_get(&ctx->pool, ctx->flags);

        if (bignum) 
        {
            BN_zero(bignum);
            bignum->flags &= (~BN_FLG_CONSTTIME);

            ctx->used++;
            CTXDBG("STEP : BN_CTX_get()", ctx);
        } 
        else 
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }

        return bignum;
    } 

    return NULL;
}