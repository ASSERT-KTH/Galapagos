Variant 1: Using implicit check instead of explicit checking for NULL

BIGNUM *BN_CTX_get(BIGN_CTX *ctx) 
{
  BIGNUM *ret;

  CTXDBG("ENTER BN_CTX_get()", ctx);
  if (ctx->err_stack || ctx->too_many)
      return NULL;

  ctx->too_many = !(ret = BN_POOL_get(&ctx->pool, ctx->flags));
 
  /* Only proceed further if ctx->too_many is not set */
  if (!ctx->too_many) {
     BN_zero(ret);
     ret->flags &= (~BN_FLG_CONSTTIME);
     ctx->used++;
     CTXDBG("LEAVE BN_CTX_get()", ctx);
     return ret;
  }

  ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
  return NULL;
}


Variant 2: Reduce nested code

BIGNUM *BN_CTX_get(BN_CTX *ctx) 
{
  BIGNUM *ret;

  CTXDBG("ENTER BN_CTX_get()", ctx);
  
  if (ctx->err_stack || ctx->too_many || 
     (ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
    ctx->too_many = 1;
    ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    return NULL;
  } 
  
  BN_zero(ret);
  ret->flags &= (~BN_FLG_CONSTTIME);
  ctx->used++;

  CTXDBG("LEAVE BN_CTX_get()", ctx);

  return ret;
}


Variant 3: Inverting condition branches

BIGNUM *BN_CTX_get(BN_CTX *ctx) 
{
  BIGNUM *ret;

  CTXDBG("ENTER BN_CTX_get()", ctx);
  
  if (!(ctx->err_stack || ctx->too_many) &&
     (ret = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) {

    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
  
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
  } 

  ctx->too_many = 1;
  ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
  return NULL;
}
