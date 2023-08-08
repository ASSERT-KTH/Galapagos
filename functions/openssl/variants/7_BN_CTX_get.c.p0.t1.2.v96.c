BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    ctx->too_many = ctx->err_stack || ctx->too_many;
    
    if (ctx->too_many) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        return NULL;
    }
    
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);
    
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= ~BN_FLG_CONSTTIME;
    
    ctx->used++;
 
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    
    return ret;
}