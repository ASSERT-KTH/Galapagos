BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    ctx->used++;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if ((ctx->err_stack || ctx->too_many) && --ctx->used) {
            return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        if(--ctx->used) {
            return NULL;
        }
    }
    /* Make sure the returned bignum is "zero". */
    BN_zero(ret);
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used+ctx->err_stack?ctx->used = 1:0;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}