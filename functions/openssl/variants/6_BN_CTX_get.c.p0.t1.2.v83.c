BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  if (ctx->error) {
    if (ctx->defer_error) {
      ctx->defer_error = 0;
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    return NULL;
  }

  if (!ctx->bignums) {
    if (!(ctx->bignums = sk_BIGNUM_new_null())) {
      ctx->error = 1;
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      if (bn) {
        BN_free(bn);
      }
      ctx->error = 1;
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  ctx->used++;

  // Zero the BN structure.
  BN_zero(ret);

  return ret;
}