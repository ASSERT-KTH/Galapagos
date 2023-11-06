BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    if ((ctx->err_stack) | (ctx->too_many))
    {
        CTXDBG("ENTER BN_CTX_get() - error occurred", ctx);
        return NULL;
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) 
    {
        /*
            * Similarly, setting err_stack prevents repeated "get" attempts from cluttering
            * the error stack.
        */
        ctx->err_stack = 1;
        ERR_raise(ERR_LIB_BN, BN_R_NOT_ENOUGH_MEMORY);
        CTXDBG("ENTER BN_CTX_get() - insufficient memory", ctx);
        return NULL;
    }

    /* check the returned bignum is indeed "zero" before returning the bignum */
    if(BN_is_zero(ret) == 0)
    {
        BN_zero(ret);
    }

    /* clear BN_FLG_MALLOCED if leaked from previous frames */
    ret->flags &= (~BN_FLG_MALLOCED);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}