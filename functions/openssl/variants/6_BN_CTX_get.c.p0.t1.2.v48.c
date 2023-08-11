BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Checking operation failure first and abort early.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->defer_error = 0;
    }
    return NULL;
  }
  
  // Initialize ctx bignums if it is null
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all bignums are used, create a new one
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL|| !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  // Increment used counter after getting bignum value
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used++);
  // Set the new bignum to zero
  BN_zero(ret);
  return ret;
}