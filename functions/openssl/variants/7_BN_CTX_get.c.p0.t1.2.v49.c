BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    if (ctx == NULL)
        return NULL;
        
    CTXDBG("START BN_CTX_get()", ctx);

    if (ctx->err_stack)
        return NULL;

    if (ctx->too_many) {
        ctx->too_many = 0;
        return NULL;
    }

    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
 
    BN_zero(ret);
  
    if (ret->flags & BN_FLG_CONSTTIME)
        ret->flags &= (~BN_FLG_CONSTTIME); 
       
    ctx->used++;
   
    CTXDBG("END BN_CTX_get()", ctx);

    return ret;
}