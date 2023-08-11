BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Checking for erroneous status.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Setting up memory for big numbers if it hasn't been allocated yet.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Checking if memory allocation was successful.
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all memory for big numbers has been utilized, allocate more.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    // Checking if new big number generation was successful.
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if(bn) {
          BN_free(bn);
      }
      ctx->error = 1;
      return NULL;
    }
  }

  // Obtain one value and zero it.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  if (ret) {
      BN_zero(ret);
  }
  
  // Increment usage counter.
  ctx->used = ctx->used + 1;

  return ret;
}