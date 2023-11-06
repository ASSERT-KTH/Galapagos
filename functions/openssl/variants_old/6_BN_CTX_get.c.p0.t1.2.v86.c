
BIGNUM *BN_CTX_get(BN_CTX *ctx)  {
  // Test for errors first, if does then all operations fail.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // if the `bignums` property of the context object is NULL,
  // create a new BIGNUM
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Unable to create a new BIGNUM proceed null to signal failure
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all slots got used up, create a new one and place to the end.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    if (!sk_BIGNUM_push(ctx->bignums, BN_new()) || BN_new() == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    }
  }

  // Get the current instance, zero out and return to the invoking routine.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used++);
  BN_zero(ret);
  return ret;
}
