BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN", ctx);
  
    if (ctx->err_stack || ctx->too_many) return NULL;

    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;

        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        
        return NULL;
    }
  
    BN_zero(ret);

    /* Erase current BN_FLG_CONSTTIME flag if it's present */
    if (ret->flags & BN_FLG_CONSTTIME)
         ret->flags ^=BN_FLG_CONSTTIME;
         
    ++ctx->used;

    CTXDBG("END", ctx);
    
    return ret;
}