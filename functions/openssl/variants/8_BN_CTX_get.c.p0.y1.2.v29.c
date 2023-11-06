BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *returnNum;
    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    bool ctxError = ctx->err_stack || ctx->too_many;
    
    if (ctxError) {
        return NULL;
    } else {
        if (!(returnNum = BN_POOL_get(&ctx->pool, ctx->flags))) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        } else {
            BN_zero(returnNum);
            returnNum->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            return returnNum;
        }
    }

    return NULL;
}