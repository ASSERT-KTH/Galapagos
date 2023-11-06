BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Do not proceed in case of an error
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Initialize bignums array if it does not exist
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Return error if bignums cannot be initialized
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // Check if we have exceeded the number of bignums and try to add a new one
  if ((ctx->used > sk_BIGNUM_num(ctx->bignums)) && (ctx->used++ == sk_BIGNUM_num(ctx->bignums)) ) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  // Cache the return bignum before clearing it
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);

  return ret;
}