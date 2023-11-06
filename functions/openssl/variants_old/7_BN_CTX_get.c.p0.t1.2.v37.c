BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get(): alter", ctx);
    if (ctx->err_stack) {
        return NULL;
    }    
    if (ctx->too_many){
        ERR_raise(ERR_LIB_BN, BN_R_ATTEMPTS_FAILED);
        return NULL;        
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        // setting too_many prevents repeated retrieval attempts from \
        // cluttering the error stack
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    // init 'ret' to zero
    BN_zero(ret);
    // clear BN_FLG_CONSTTIME if repeated from call stacks
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used = 1 + ctx->used;
    CTXDBG("LEAVE BN_CTX_get(): alter", ctx);
    return ret;
}