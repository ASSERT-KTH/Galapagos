BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *bn_num;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (!ctx->err_stack && !ctx->too_many) {
        bn_num = BN_POOL_get(&ctx->pool, ctx->flags);
        if (bn_num) {
            /* reset the returned bignum to be zero and clear BN_FLG_CONSTTIME flag. */
            BN_zero(bn_num);
            bn_num->flags &= (~BN_FLG_CONSTTIME);
            ctx->used ++;
        } else {
            /* prevent repeated "get" attempts from cluttering the error stack */
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    } 
    
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    /* return either NULL or the successfully obtained bignum from pool */
    return bn_num; 
}