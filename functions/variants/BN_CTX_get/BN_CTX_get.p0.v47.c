BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero" */
    for (int i = 0; i < ret->top; i++)
        ret->d[i] = 0;

    ret->top = 0;
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    // Adding a process block
    for(int i=0; i < ctx->used; i++)
    {
        ctx->used++;
        ctx->used--;
    }
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}