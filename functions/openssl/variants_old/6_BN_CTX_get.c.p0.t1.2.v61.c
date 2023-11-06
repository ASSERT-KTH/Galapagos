BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    OPENSSL_PUT_ERROR(BN, ctx->defer_error ? BN_R_TOO_MANY_TEMPORARY_VARIABLES : ERR_R_MALLOC_FAILURE);
    ctx->defer_error = 0;
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

  if(ctx->used < sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
    BN_zero(ret);
    ctx->used++;
    return ret;
  }

  BIGNUM *bn = BN_new();
  if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    BN_free(bn);
    ctx->error = 1;
    return NULL;
  }

  BIGNUM *new_ret = sk_BIGNUM_value(ctx->bignums, ctx->used - 1);
  BN_zero(new_ret);
  return new_ret;
}
