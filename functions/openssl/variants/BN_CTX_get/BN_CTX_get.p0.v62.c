BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_modified_get()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;

    int additional_flags = 0;
    additional_flags |= BN_FLG_TMP_FREE;

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags | additional_flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_modified_get()", ctx);
    
    return ret;
}