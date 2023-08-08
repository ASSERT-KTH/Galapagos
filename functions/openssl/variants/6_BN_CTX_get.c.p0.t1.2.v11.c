BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Initialize bignums if not done so
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // Add more bignums if used up
  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if (bn) {
        BN_free(bn);
      }
      ctx->error = 1;
      return NULL;
    }
  }

  // Return a zero value BIGNUM and increase the record of used BIGNUM
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  if (!(BN_set_word(ret, 0))) {
    ctx->error = 1;
    return NULL;
  } 
  ++ctx->used;

  return ret;
}