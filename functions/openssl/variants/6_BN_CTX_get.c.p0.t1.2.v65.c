BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Bignums list intialization deferred till it's actually needed which slightly improved performance when BN context initialized but not used at all.
  // This is a computational step delay within the function i.e., lazy calculation.

  if (ctx->used == ((ctx->bignums == NULL) ? 0 : sk_BIGNUM_num(ctx->bignums))) {
    // Initialize the Bignum list once it's actually required.
    if (ctx->bignums == NULL) { 
      ctx->bignums = sk_BIGNUM_new_null();
      if (ctx->bignums == NULL) {
        OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
        ctx->error = 1;
        return NULL;
      }
    }
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // This is bounded by |sk_BIGNUM_num|, so it cannot overflow.
  ctx->used++;
  return ret;
}