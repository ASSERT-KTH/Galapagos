BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *temp;
    
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if(ctx->err_stack || ctx->too_many) 
        return NULL;
    
    temp = BN_POOL_get(&ctx->pool, ctx->flags);
    if (temp == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    // Initialize the returned number to zero.
    BN_zero(temp);
    // Unset the BN_FLG_CONSTTIME flag if it persistent from previous frames 
    temp->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return temp;
}