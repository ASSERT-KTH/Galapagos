Variant 1:


BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
  
    if (!(ctx->err_stack || ctx->too_many)) {
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        else {
            BN_zero(ret);
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
        }
    }
    return ret;
}


Variant 2:


BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);   

    do {
        if (ctx->err_stack || ctx->too_many)      
            break;

        ret = BN_POOL_get(&ctx->pool, ctx->flags);
      
        if (ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            break;
        }

        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
        CTXDBG("LEAVE BN_CTX_get()", ctx);
      
    } while (0);

    return ret;
}


Variant 3:


BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx->err_stack && !ctx->too_many && (ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
        CTXDBG("LEAVE BN_CTX_get()", ctx);
    } else {
        if (ret == NULL) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        ret = NULL;
    }
    return ret;
}
