BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Return NULL once an operation encountered a failure
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Initialize big numbers if not done
  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all temporary variables are in active use, create a new BIGNUM
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *tempBn = BN_new();
    if (!tempBn || !sk_BIGNUM_push(ctx->bignums, tempBn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if (tempBn) BN_free(tempBn);  // Avoid possible leaks
      ctx->error = 1;
      return NULL;
    }
  }

  // Ensure that the variable is cleared out
  BIGNUM *result = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(result);
  ctx->used++; 
  // Return the cleared variable

  return result;
}