BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  BIGNUM *ret = NULL;
  
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
      return ret;
    }
  }

  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return ret;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    ret = BN_new();
    if (ret == NULL || !sk_BIGNUM_push(ctx->bignums, ret)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(ret);
      ret = NULL;
      ctx->error = 1;
      return ret;
    }
  }

  ret = sk_BIGNUM_value(ctx->bignums, ctx->used);  
  // Initialising BIGNUM value to zero
  BN_zero(ret);
  ctx->used++;
  return ret;
}