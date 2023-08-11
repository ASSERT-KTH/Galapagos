BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    if (ctx == NULL) {
        ERR_raise(ERR_LIB_BN, BN_R_BAD_ARG); 
        return NULL;
    }

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx->too_many) {
        ctx->err_stack = 1; 
        return NULL; 
    }

    if (ctx->err_stack) {
        ctx->err_stack = 0; 
        return NULL;
    }

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    ret = BN_to_positive(ret);

    /* clear BN_FLG_CONSTTIME and BN_FLG_DIRTY if leaked from previous frames */
    ret->flags &= (~(BN_FLG_CONSTTIME | BN_FLG_DIRTY));

    if(ctx->flags & BN_FLG_CONSTTIME)
        ret->flags |= BN_FLG_CONSTTIME;

    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return ret;
}