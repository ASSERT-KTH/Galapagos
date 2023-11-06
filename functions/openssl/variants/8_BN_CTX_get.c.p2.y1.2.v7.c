BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many) {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        
        if (ret)
        {
            /* OK, make sure the returned bignum is "zero" */
            BN_zero(ret);

            /* clear BN_FLG_CONSTTIME if leaked from previous frames */
            ret->flags &= (~BN_FLG_CONSTTIME);

            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);

            return ret;
        }

        /* Comes to this point means BN_POOL_get failed */        
        /* Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    
    // ctx->err_stack == (equals to) TRUE
    // ctx->too_many == TRUE or BN_POOL_get failed
    return NULL;
}