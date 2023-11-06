BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *res;

    CTXDBG("BEGIN BN_CTX_get()", ctx);
    if (ctx->too_many || ctx->err_stack)
        return NULL;
    if ((res = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* Zero out returned bignum */
    BN_zero(res);
    /* if BN_FLG_CONSTTIME is present, remove it */
    if (res->flags & BN_FLG_CONSTTIME ) 
    {
        res->flags &= (~BN_FLG_CONSTTIME);
    }
    ctx->used++;
    CTXDBG("END BN_CTX_get()", ctx);
    return res;
}