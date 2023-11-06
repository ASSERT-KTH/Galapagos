Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *OutputBignum;

    CTXDBG("BEGIN BN_CTX_get()", ctx);
    if (ctx->too_many || ctx->err_stack)
        return NULL;

    OutputBignum = BN_POOL_get(&ctx->pool, ctx->flags);
    if (OutputBignum == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(OutputBignum);
    OutputBignum->flags &= (~BN_FLG_CONSTTIME);

    ctx->used++;
    CTXDBG("EXIT BN_CTX_get()", ctx);
    return OutputBignum;
}


Variant 2:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *newBignum;

    CTXDBG("Calling BN_CTX_get()", ctx);
    if (!ctx->err_stack && !ctx->too_many) {
	       newBignum = BN_POOL_get(&ctx->pool, ctx->flags);
	       if (newBignum != NULL) {
               BN_zero(newBignum);
	           newBignum->flags &= (~BN_FLG_CONSTTIME);
	           ctx->used++;
           } else {
               ctx->too_many = 1;
	           ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
           } 
	   }
    CTXDBG("Finished BN_CTX_get()", ctx);
    return newBignum;
}


Variant 3:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    if(ctx->err_stack || ctx->too_many){
        CTXDBG("Automatic return from BN_CTX_get()", ctx);
        return NULL;
    }

    BIGNUM *ret;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if(ret != NULL){
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
        CTXDBG("Successful exit from BN_CTX_get()", ctx);
        return ret;
    }

    ctx->too_many = 1;
    ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    CTXDBG("Failed exit from BN_CTX_get()", ctx);
    return NULL;
}
