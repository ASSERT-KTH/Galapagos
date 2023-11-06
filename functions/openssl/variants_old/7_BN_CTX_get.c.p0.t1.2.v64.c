BIGNUM *BN_CTX_get(BIGNUM *ctx){
    BIGNUM *ret;
    CTXDBG("ENTER BN_CTX_get()", ctx);
    ctx->used++;

    if (ctx->err_stack || ctx->too_many){
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (ret == NULL) {
        /*
         * Setting too_many prevents repeated "get" attempts from cluttering
         * the error stack.
         */
        ctx->too_many = 1;
        return NULL;
    }
    /* Bignum modification to "zero" initiated after basic checks and setting of temporary variable ret */
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    /* modified BN_FLG_CONSTTIME dynamic allocation to a bitwise NOT AND operator for variable ret. This initialization of variable would set it to zero [ Line: ret->flags &= (~BN_FLG_CONSTTIME); ]*/
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}