BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Check the pre-existing error status
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Allocating Big numbers if they aren't already
  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Memory allocation check.
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = true;
      return NULL;
    }
  }

  if ((ctx->used == sk_BIGNUM_num(ctx->bignums))) {
    BIGNUM *bn = BN_new();
    // Check the push operation success.
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = true;
      return NULL;
    }
  }

  BIGNUM *bn_return = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(bn_return);
 
  ctx->used++;
  return bn_return;
}