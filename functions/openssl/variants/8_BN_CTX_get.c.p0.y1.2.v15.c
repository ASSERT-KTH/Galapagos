BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *res;
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) return NULL;
    else res = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (!res) {
       ctx->too_many = 1;
       ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
       return NULL;
    } else {
       /* Release the returned bignum by reinitializing */

        BN_zero(res);
        /* solves situation for BN_FLG_CONSTTIME if escaped from older frames.*/
        
        res->flags = res->flags & (~BN_FLG_CONSTTIME);
        ctx->used++;
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return res;
    }
}