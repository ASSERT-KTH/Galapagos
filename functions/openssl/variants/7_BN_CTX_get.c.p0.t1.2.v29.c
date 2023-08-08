BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack) {
        ERR_raise(ERR_LIB_BN, BN_R_ERROR_STACK);
        return NULL;
    }

    if (ctx->too_many) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    switch((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
        case 0 :
        /* Setting too_many prevents repeated "get" attempts from cluttering the error stack */
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        default :
        /* OK, make sure the returned bignum is "zero-to the memory properties" */
            BN_zero(ret);
            /* clear BN_FLG_CONSTTIME if leaked from previous frames */
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            return ret;
    }
}