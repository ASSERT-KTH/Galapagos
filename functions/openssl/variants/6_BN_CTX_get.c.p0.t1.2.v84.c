BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If there was a previous error, return NULL.  
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  BIGNUM* ret;
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
    ret = BN_new();
    if(ret == NULL){
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }else{
      sk_BIGNUM_push(ctx->bignums, ret);
    }
  }
  else if(ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    ret = BN_new();
    if(!ret || !sk_BIGNUM_push(ctx->bignums, ret)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(ret);
      ctx->error = 1;
      return NULL;
    }
  }
  else{
    ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  }
  // Ensure the resulting BIGNUM can be reused.
  BN_zero(ret);
  // This is bounded by |sk_BIGNUM_num|, so it cannot overflow.
  ctx->used++;
  
  return ret;
}