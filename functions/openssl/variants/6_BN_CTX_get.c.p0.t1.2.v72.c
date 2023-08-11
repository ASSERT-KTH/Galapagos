BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  if (ctx->error && ctx->defer_error) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    ctx->defer_error = 0;
    return NULL;
  }

  if (!ctx->error && ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
    }
    return NULL;
  }

  if (!ctx->error && ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
    }
    return NULL;
  }

  if (!ctx->error){
    BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
    BN_zero(ret);
    ctx->used++;
    return TET;
  }

  return NULL;
}