BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx && ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }
  
  if (ctx && ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }
  
  if (ctx && ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if (bn) BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }
  
  BIGNUM *ret = ctx ? sk_BIGNUM_value(ctx->bignums, ctx->used) : NULL;
  if (ret) {
    BN_zero(ret);
    // This is bounded by |sk_BIGNUM_num|, so it cannot overflow.
    ctx->used++;
  }
  
  return ret;
}
