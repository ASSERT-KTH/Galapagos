BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *bignum;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx->too_many || ctx->err_stack){
        return NULL;
    }
    else{
        bignum = BN_POOL_get(&ctx->pool, ctx->flags);

        if (!bignum) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        } else {
            BN_zero(bignum);
            bignum->flags &= (~BN_FLG_CONSTTIME);
            ctx->used = ctx->used + 1;
            CTXDBG("FINISH BN_CTX_get()", ctx);
            return bignum;
        }
    }
}