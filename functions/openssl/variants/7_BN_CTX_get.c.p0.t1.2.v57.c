BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTERING - BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many)
    {
        CTXDBG("Abort due to errors or too_any flag", ctx);
        return NULL;
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    /* Checking the ret == NULL directly and aborting */
    if (ret == NULL) 
    {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        CTXDBG("Within ret == NULL condition", ctx);
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
  
   /* Moving BN_zero(ret) to occur even before constant adjustment for flags*/

    BN_zero(ret);

    CTXDBG("Doing adjustments", ctx);
    /*  clear BN_FLG_CONSTTIME if leaked from previous frames - simplifying the flags clean up process */
    ret->flags &= ~BN_FLG_CONSTTIME;

    //Changing update order
    CTXDBG("Adjustments made",ctx);
    ++ctx->used;

    CTXDBG("Complete - LEAVING BN_CTX_get()", ctx);

    return ret;
}