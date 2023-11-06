BIGNUM *BN_CTX_get(BN_ATTR *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many)
    {
        ERR_raise(ERR_LIB_BN, BN_R_STACK_OR_LIMIT_ERROR);
        return NULL;
    }
        
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    else
    {
        /* OK, make sure the returned bignum is "zero" */
        if(BN_value(ret) != 0) //Ensuring 0
        {
            BN_zero(ret);
        }

        /* clear BN_FLG_CONSTTIME if leaked from previous frames */
        if (ret->flags & BN_FLG_CONSTTIME) //Suppressing additional operation if not needed.
        {
            ret->flags &= (~BN_FLG_CONSTTIME);
        }

        ++ctx->used;
        CTXDBG("LEAVE BN_CTX_get(): bignum = 0, constTimeflgCleared = true", ctx);
    }
        
    return ret;
}