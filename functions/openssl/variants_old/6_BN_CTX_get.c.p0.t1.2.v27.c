BIGNUM *BN_CTX_get(BN_CTX *ctx) {
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

  BIGNUM *ret = NULL;

  if (ctx->used < sk_BIGNUM_num(ctx->bignums)) {
    ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  } else {
    ret = BN_new();
    if (ret == NULL || !sk_BIGNUM_push(ctx->bignums, ret)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(ret);
      ctx->error = 1;
      ret = NULL;
    }
  }

  if (ret) {
    BN_zero(ret);
    ctx->used++;
  }

  return ret;
}