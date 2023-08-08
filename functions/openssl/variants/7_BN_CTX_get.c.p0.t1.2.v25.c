BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    int flagBackup;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (!ctx)
        return NULL;

    flagBackup = ctx->flags;

    if (ctx->err_stack || ctx->too_many) {
        ctx->flags = flagBackup;  // Restore original flags.
        return NULL;
    }

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->flags = flagBackup;  // Restore original flags.
        return NULL;
    }
 
    // Ensuring the big number returned is zero
    // And decrement the used count
    // Hence "undoing" one increment that will be made later on
    ctx->used--;
    
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    
    ctx->used++;
    ctx->flags = flagBackup;  // Restore original flags.

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}