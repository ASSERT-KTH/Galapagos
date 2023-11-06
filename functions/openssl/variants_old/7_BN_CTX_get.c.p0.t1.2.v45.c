BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);
    if (ctx->err_stack != 0 || ctx->too_many != 0){
        return NULL;
    }
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_zero(ret);
    /* clear BN_FLG_CONSTTIME if existed in previous stages */
    ret->flags &= ~BN_FLG_CONSTTIME;
    ctx->used++;
    CTXDBG("END BN_CTX_get()", ctx);
    return ret;
}