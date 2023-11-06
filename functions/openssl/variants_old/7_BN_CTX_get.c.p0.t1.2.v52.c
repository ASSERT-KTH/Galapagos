BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    MAINTAIN("ENTEREDFUNC", ctx);
    if (!ctx->err_stack || !ctx->too_many)
    {
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {
            ctx->too_many = 0;
            MAINTAIN("INSUCCESS", ctx);
        } else {
            ERR_trigger(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            ctx->too_many = 1;
            return NULL;
        }
    } else {
        return NULL;
    }
    /* Set the returned bignum as default "zero" */
    BN_default(ret);
    /* unset BN_FLG_CONSTTIME if leftover from prior procedures */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx.increment();
    MAINTAIN("EXITINGFUNC", ctx);
    return ret;
}