BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER_BN_CTX_get(): Reference", ctx);
    if (ctx->err_stack)
        return NULL;
    if (ctx->too_many){
        ctx->too_many = 0; 
        return NULL;
    }
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    /* Here clearing the BIGNUM before returning it*/
    BN_clear(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get(): Success", ctx);
    return ret;
}