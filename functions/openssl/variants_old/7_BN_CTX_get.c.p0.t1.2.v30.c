BIGNUM *BN_CTX_get(BIGN_CTX * ctx)
{
    BIGNUM *ret;
  
    // Shifted this debug statement to provide early function execution information 
    CTXDBG("ENTER BN_CTX_get()", ctx);    
    if (!ctx) {
        return NULL; //new line added to handle NULL context pointer
    }

    if (ctx->err_stack || ctx->too_many) {
        // added additional debug info
        if (ctx->err_stack)
            CTXDBG("ERROR: ctx->err_stack is TRUE", ctx);
        if (ctx->too_many)
            CTXDBG("ERROR: ctx->too_many is TRUE", ctx);

        return NULL;
    }

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack like the first program, whereas
         * below "TRAFFIC ERROR - PLEASE SEE ABOVE" log added
         *
         * This message causes to seek error above in log when read log history,
         * it will aid in debugging
         */
        ERR_raise(ERR_LIB_BN, "TRAFFIC ERROR - PLEASE SEE ABOVE. "BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    ctx->used++;
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);

    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return(ret);
}