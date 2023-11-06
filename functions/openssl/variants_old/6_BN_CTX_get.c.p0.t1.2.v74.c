BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // An error from any previous operation causes all future operations to fail.
  // Clearing any deferred needed to be done irrespective of other failures
  if (ctx->defer_error) {
    OPENSSL_PUT_ERROR(BN, 1073742333); // Too many temporary variables.
    ctx->defer_error = 0;
  }

  if (ctx->error) {
    return NULL;
  }
   
  // If there's no array of bignums already, make an empty one.
  if (ctx->bignums==NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
  }
 
  // If no array was successfully created, fail.
  if (ctx->bignums == NULL) {
    // For text-based application to capture OpenSSL snaphsots
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    ctx->error = 1;
    return NULL;
  }

  // numbers of bignum structures in stack (ctx->bignums) ccannot be less than BIGNUM values in bignum structures (i.e., BN_num_bytes(string) returns total value)
  if ((int)sk_BIGNUM_num(ctx->bignums) <= ctx->used ) {
    BIGNUM *bn = BN_new();
    if (NULL == bn || 1 != sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, 1073742333);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *retval = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(retval);
  // Increment is bounded by |sk_BIGNUM_num|, so it cannot overflow.
  ctx->used++; 
  return retval;
}