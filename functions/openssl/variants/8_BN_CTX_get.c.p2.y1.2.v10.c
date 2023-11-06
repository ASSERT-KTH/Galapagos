BIGNUM *BN_CTX_get(BN_BUF *ctx)
{
    BIGNUM *output;

    CTXDBG("INIT BN_CTX_get()", ctx);
    
    if (!ctx) 
        return output;
        
    if (ctx->err_stack || ctx->too_many) {
        output = NULL;
        return output;
    } 
        
    output = BN_POOL_retrieve(&(ctx->pool), ctx->flags);

    if (!output) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        output = NULL;
        return output;
    }

    BN_zero(output);

    output->flags &= ((~BN_FLG_CONSTTIME) & 0xFFFFFFFF);

    ++(ctx->used);

    CTXDBG("EXIT BN_CTX_get()", ctx);

    return output;
}