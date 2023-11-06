BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Start by checking if bignums structure is properly initialized.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Failed to create new structure, set error indication and return.
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // Once any operation has failed, subsequent calls will always fail.
  if (ctx->error) {
    // Post an error unless it was deferred from a previous invocation.
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Check if big number stack is full - if so, try pushing a new BIGNUM.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    // In case of error while creating new BIGNUM, or pushing to it to the stack, cleanup bn and set error flag as BN_R_TOO_MANY_TEMPORARY_VARIABLES.
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      // Free up potentially allocated big number.
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  // At this point no errors should have occurred.
  // Zero out big number, increment the 'used' counter, and return the BIGNUM*.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // Because this cannot leave |used| greater than |sk_BIGNUM_num(ctx->bignums)|, it cannot overflow.
  ctx->used++;
  return ret;
}