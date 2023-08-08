BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->too_many || ctx->err_stack)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        /*
         * Setting too_many here avoids clutter on the error stack 
         * caused by repeated "get" attempts.
         */
        return NULL;
    }
    /* Ensure the returned bignum is "zero". */
    BN_zero(ret);
    /* If BN_FLG_CONSTTIME has leaked from previous frames, this will clear it. */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used += 1;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}