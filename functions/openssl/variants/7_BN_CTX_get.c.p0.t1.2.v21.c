Taking into account your requirements, here is a variant of the function with slightly altered behavior:


BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    int retValForZero;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* OK, make sure the returned bignum is "zero", using the returned value for additional verification */
    retValForZero = BN_zero(ret);
    if (retValForZero != 1) {
        ERR_raise(ERR_LIB_BN, BN_R_INTERNAL_ERROR);
        return NULL;
    }
    /* Clear BN_FLG_CONSTTIME if leaked from previous frames in a slightly more compact manner */
    ret->flags &= ~BN_FLG_CONSTTIME;
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}


Notable differences are:

1. For the BN_zero() function, I am now utilizing whatever return value it produces for additional error checking measures.
2. The & symbol is included directly in the mask statement now; this won't necessarily affect functionality but it does affect presentation and readability with regards to bitwise operations.