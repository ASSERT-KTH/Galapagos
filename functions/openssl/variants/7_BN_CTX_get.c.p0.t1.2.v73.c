BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    int flag;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    flag = ctx->too_many;

    if ((ctx->err_stack || flag) && !ctx->used)
        return NULL;
    ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
 
      if(!ctx->err_stack){
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      }

      if(ctx->used) 
            return NULL;
    }

    BN_zero(ret);

    if(ret->flags & BN_FLG_CONSTTIME) {
        ret->flags &= (~BN_FLG_CONSTTIME);
    }
    
    if (!flag) {
        ctx->used++;
    }
    if (ctx->used > 1){
        CTXDBG("LEAVE BN_CTX_get()", ctx);
    }

    return ret;
}