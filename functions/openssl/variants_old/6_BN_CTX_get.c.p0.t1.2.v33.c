BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Instead of checking for a specific error state,
  // we first initialize a large number if the list of big number is not available
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If an operation overflow error has occurred, reflect to caller
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Try to append new BIGNUM to stack if existing stack is fully used  
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); 
      ctx->error = 1;
      return NULL;
    }
    if( !sk_BIGNUM_push(ctx->bignums, bn) ) {
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  // the returned BIGNUM should start with a zero value
  if( BN_is_zero(ret) == 0 ) {
    BN_zero(ret);
  }
  
  ctx->used++;
  return ret;
}