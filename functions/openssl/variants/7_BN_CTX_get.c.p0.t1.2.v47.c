BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *return_val;

    CTXDBG("FUNCTION START : BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_much)
        return NULL;
    if ((return_val = BN_POOL_get(&ctx->pool, ctx->switches)) == NULL) {
        
        ctx->too_much = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    BN_zero(return_val);

    return_val->switches &= (~BN_FLG_CONSTTIME);
    ctx->consumed++;
    CTXDBG("FUNCTION END : BN_CTX_get()", ctx);
    return return_val;
}