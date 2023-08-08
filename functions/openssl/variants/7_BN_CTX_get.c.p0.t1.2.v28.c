BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN BN_CTX_get()", ctx);
    if (ctx->err_stack)
        return NULL;

    if (ctx->too_many)   // break conditions for better readability
        return NULL;

    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    ret->flags &= (~BN_FLG_CONSTTIME);  // moving this up here because, flags of returned Bignum can be cleared straightway, regardless of any calculations done after it.
  
    /* OK, make sure the returned bignum is "zero" */
    BN_zero(ret);

    ctx->used = ctx->used+1;
    if (ctx->used < 10) 
      CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}