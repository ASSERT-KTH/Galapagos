BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (!ctx->bignums) {
    if(!(ctx->bignums = sk_BIGNUM_new_null())) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret;

  if (ctx->used != sk_BIGNUM_num(ctx->bignums)) {
    ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  } else {
    if(!(ret = BN_new()) || !sk_BIGNUM_push(ctx->bignums, ret)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(ret);
      ctx->error = 1;
      return NULL;
    }
  }

  BN_zero(ret);
  // This is bounded by |sk_BIGNUM_num|, so it cannot overflow.
  ctx->used++;
  return ret;
}