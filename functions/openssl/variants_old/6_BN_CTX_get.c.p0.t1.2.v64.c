BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Abort operation if there was a prior error
  if (ctx->error != 0) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (!(ctx->bignums)) {
    // Create if not existing
    ctx->bignums = sk_BIGNUM_new_null();
    // Report Error if failed to create 
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    // If reached limit increase capacity 
    BIGNUM *bn = BN_new();
    if (bn == NULL || !(sk_BIGNUM_push(ctx->bignums, bn))) {
      // Put error, free resources and return if failed
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  // Get the big number value  
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  
  ctx->used = (ctx->used) + 1;
  
  // Otherwise, return the big number value
  return ret;
}