BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);  
    if (ctx->err_stack || ctx->too_many){
        ret = NULL;
    }
    else{
        ret = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret == NULL) {
           /*
            * Setting too_many stops "get" attempts from spamming 
            * the error stack.
            */
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        else {
            /* OK, ensure the returned bignum is "zero" */
            BN_zero(ret);
            /* reset BN_FLG_CONSTTIME if leaked from earlier calls */
            ret->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        }
    }  
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}