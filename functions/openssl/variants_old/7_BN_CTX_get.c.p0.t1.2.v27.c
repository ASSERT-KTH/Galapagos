BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    /* Consider an 'else' ladder which is exactly the same */
    if (ctx->err_stack)
        return NULL;
    else if (ctx->too_many)
        return NULL;
    else if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* Short-circuit earlier if 'ret' is 'NULL' to prevent potential pointer dereference issues */
    if(ret == NULL) {
        return NULL;
    }

    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);

    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    /* We can simplify this bitwise operation */
    ret->flags &= ~BN_FLG_CONSTTIME;

    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}
