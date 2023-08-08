BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Returns NULL immediately if error has occurred in past operations
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();

    // Handles allocation failure.
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  if (ctx->used != sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = sk_BIGNUM_value(ctx->bignums, ctx->used);
    BN_zero(bn);
    ctx->used++;
    return bn;
  }
  
  BIGNUM *bn = BN_new();

  // Handles allocation or insertion failure.
  if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    BN_free(bn);
    ctx->error = 1;
    return NULL;
  }

  
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used - 1);
  BN_zero(ret);

  return ret;
}