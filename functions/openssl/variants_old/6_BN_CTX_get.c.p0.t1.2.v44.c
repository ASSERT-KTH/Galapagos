BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation is unsuccessful, restrict further function execution
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // If 'bignums' is uninitialized, create a new instance
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      // Terminate function execution early
      return NULL; 
    } 
  }

  // If all 'bignums' slots are allocated, overallocate another BIGNUM
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if ((bn == NULL) || (!sk_BIGNUM_push(ctx->bignums, bn))) {
      // Release 'bn' back into the ecosystem
      BN_free(bn);
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    }
  }

  // Extract the 'BIGNUM' value from 'bignums' at position 'used'
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  // Set 'ret' to 0
  BN_zero(ret);
  // As long as the count 'used' does not surpass 'sk_BIGNUM_num', increment
  if (ctx->used < sk_BIGNUM_num(ctx->bignums)) {
    ctx->used++;
  }
  return ret;
}