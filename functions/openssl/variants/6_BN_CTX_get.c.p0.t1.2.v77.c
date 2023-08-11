BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Check for errors first.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Create the bignums list if none exists.
  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all available BIGNUM objects are currently in use, allocate another one.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      if (bn) {
        BN_free(bn);
      }
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // Extend the number of used BIGNUM objects.
  ctx->used++;
  return ret;
}