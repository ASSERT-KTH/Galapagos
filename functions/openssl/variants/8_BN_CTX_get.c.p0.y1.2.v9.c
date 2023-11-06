BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{
    CTXDBG("BEGIN BN_CTX_get()", ctx);
    
    if (ctx->err_stack || ctx->too_many) {
        return NULL;
    }
   
    BIGNUM *cnst = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!cnst) {
       
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
  
    BN_zero(cnst);

    cnst->flags = cnst->flags & (~BN_FLG_CONSTTIME);

    ctx->used++;

    CTXDBG("FINISH BN_CTX_get()", ctx);

    return cnst;
}