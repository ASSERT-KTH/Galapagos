BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        return NULL;
    } else {
        if (ctx->too_many) {
            ctx->too_many = 0;
        }
    }
    /*
     * Setting too_many to 0 if it was previously set to prevent repeated "get" attempts from cluttering
     * the error stack.
     */
    ERR_clear_error();
    
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);

    if (ctx->used < UINT_MAX) {/* Make sure used is never greater than UINT_MAX */
        ctx->used++;
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}