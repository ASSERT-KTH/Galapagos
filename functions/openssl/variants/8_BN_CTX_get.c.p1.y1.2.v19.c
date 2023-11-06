Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *res;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        return NULL;
    }

    res = BN_POOL_get(&ctx->pool, ctx->flags);

    if (res == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(res);
    res->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return res;
}


Variant 2:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *fetchedBignum = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (!(ctx->err_stack || ctx->too_many)) {
        fetchedBignum = BN_POOL_get(&ctx->pool, ctx->flags);
        if (fetchedBignum != NULL) {
            BN_zero(fetchedBignum);
            fetchedBignum->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        } else {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);   
        }
    }
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return fetchedBignum;
}


Variant 3:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *num;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    do {
        if (ctx->err_stack || ctx->too_many) {
            break;
        }

        num = BN_POOL_get(&ctx->pool, ctx->flags);

        if(num == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            break;
        }

        BN_zero(num);

        num->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }
    while (0);
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return num;
}
