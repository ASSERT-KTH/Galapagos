BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, the rest would automatically fail too.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
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

  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn_new = BN_new();
    if (bn_new == NULL || !sk_BIGNUM_push(ctx->bignums, bn_new)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn_new);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret_var = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret_var);
  // This is limited by |sk_BIGNUM_num|, so an overflow can't occur.
  ctx->used++;
  return ret_var;
}