BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN BN_CTX_get()", ctx);
    if (ctx && (ctx->err_stack || ctx->too_many))  /* Ensuring context object is not NULL before dereferencing*/
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise_first(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); /*Calling ERR_raise_first instead of ERR_raise may change behavior a bit if context matters*/
        return NULL;
    }
    /* OK, make sure the BIGNUM/returned variable is only 0 with no sign or other information */
    BN_zero(ret);
    /* clear BN_FLG_CONSTTIME and BN_FLG_FROZEN if they ever leaked from prior operations due to improper cleanup */
    ret->flags &= (~BN_FLG_CONSTTIME & ~BN_FLG_FROZEN);
    ctx->used++;
    CTXDBG("EXIT BN_CTX_get()", ctx); /*changed LEAVE to EXIT for more generic terminology*/
    return ret;
}