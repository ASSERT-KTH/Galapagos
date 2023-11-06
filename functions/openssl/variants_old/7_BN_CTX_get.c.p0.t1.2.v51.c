BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *res;
    CTXDBG("ENTER: BN_CTX_get()", ctx);

    if (ctx == NULL) {
        ERR_raise(ERR_LIB_BN, BN_R_INVALID_CTX);
        return NULL;
    }

    if (ctx->err_stack != 0 || ctx->too_many != 0)
        return NULL;

    res = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (res == NULL) {
        ctx->err_stack = ERR_LIB_BN;
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(res);

    if ((res->flags & BN_FLG_CONSTTIME) != 0) {
        res->flags ^= BN_FLG_CONSTTIME;
    }
    ctx->used++;
    
    CTXDBG("LEAVE: BN_CTX_get()", ctx);
    return res;
}