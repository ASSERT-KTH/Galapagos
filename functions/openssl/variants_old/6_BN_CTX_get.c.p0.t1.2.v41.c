BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Check if the operation has failed earlier, to ensure fail safe operations.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_NO_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all bignums are used up, create a new one.
  if (ctx->used == ctx->bignums->count) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !add_BIGNUM(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_NO_TEMPORARY_VARIABLES);
      if (bn) {
        BN_free(bn);
      }
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *result = remove_BIGNUM(ctx->bignums, ctx->used);
  BN_zero(result);
  // Increment the count of used bignums, bounded by |$count|.
  ctx->used++;
  return result;
}