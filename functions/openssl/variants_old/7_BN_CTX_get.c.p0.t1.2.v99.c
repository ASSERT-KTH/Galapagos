BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("START BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) {
        CTXDBG("CONTEXT ERROR: ENTER BN_CTX_get()", ctx);
        return NULL;
    }

    if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags))) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("TOO MANY VARIABLES: ENTER BN_CTX_get()", ctx);
        return NULL;
    } else {
        /* Make sure the returned bignum is "zero" safely */
        if(!BN_is_zero(ret))
            BN_zero(ret);
        /* safe clear BN_FLG_CONSTTIME if leaked from previous frames */
        if(BN_get_flags(ret, BN_FLG_CONSTTIME))
            ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}