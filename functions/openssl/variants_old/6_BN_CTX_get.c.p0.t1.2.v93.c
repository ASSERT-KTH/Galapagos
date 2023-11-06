BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Checks if there's an error in the context
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      // Reset defer_error
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Check if something not yet allocated and try to allocate if so.
  if (ctx->bignums == nullptr) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = true;
      return nullptr;
    }
  }

  // If all bignums in the context are already used
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    bool push_result = (bn != nullptr) && sk_BIGNUM_push(ctx->bignums, bn);
    if (!push_result) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if (bn != nullptr) {
        BN_free(bn);
      }
      ctx->error = true;
      return nullptr;
    }
  }

  // Get the used bignum in the context and move to next
  BIGNUM *result = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(result);
  // Increase used bignums count as this bignum will be used
  ++(ctx->used);

  return result;
}