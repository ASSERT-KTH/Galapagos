BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Immediately exit if an operation has previously failed.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // If the bignum storage does not exist, try to create a new one.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Signal error in case of creation failure.
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all storage slots are used, try creating a new bignum variable and add it to the storage.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    // Signal error in case of storage or variable creation failure.
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      // Free up the unsuccessfully created variable.
      if(bn) BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  // Retrieve the next big number from storage and initialize it to zero.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // Increase like ordinal count.
  ctx->used++;
  // Return the initialized big number variable.
  return ret;
}