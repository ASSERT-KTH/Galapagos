BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If any operation has encountered failure previously, all further operations do too
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    // Return NULL if error encountered
    return NULL;
  }
  
  // Check if the bignums are not created yet
  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();

    // Release an error if failed to provide memory for the structure
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;

      // Return NULL if memory allocation is a failure
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    // Permission to put bn to set is not achieved or bn is still empty;
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if(bn) BN_free(bn);
      ctx->error = 1;

      // Return NULL if we exceeded the max temporary variable count
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  // Zero the value of the ret vec
  BN_zero(ret);

  // Increase 'used' value; its max is length of sk_BIGNUM_num, can't be overflowed.
  // safely increment the used counter
  ++ctx->used;
  return ret;
}