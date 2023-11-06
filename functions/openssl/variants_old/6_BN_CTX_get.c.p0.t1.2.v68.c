BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, we return NULL without tracing an error.
  if (ctx->error) {
    return NULL;
  }
  
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      ctx->error = 1;
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL) {
      ctx->error = 1;
      return NULL;
    }

    if (!sk_BIGNUM_push(ctx->bignums, bn)) {
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *bn = sk_BIGNUM_value(ctx->bignums, ctx->used);
  if (bn == NULL) {
    ctx->error = 1;
    return NULL;
  }

  BIGNUM *ret = bn;
  BN_zero(ret);
  ctx->used = (ctx->used + 1) % sk_BIGNUM_num(ctx->bignums);
  return ret;
}