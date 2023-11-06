BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *temp_num;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx && (ctx->err_stack || ctx->too_many)) {
        return NULL;
    }

    temp_num = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (temp_num == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* After successful BN_POOL_get, assign zero and handle flags */
    BN_zero(temp_num);
    temp_num->flags &= (~BN_FLG_CONSTTIME);
    
    ++ctx->used;

    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return temp_num;
}