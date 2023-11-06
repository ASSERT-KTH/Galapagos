BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // In case of an error, execute the operation has failed, they all do
  if (ctx->error) {
    ctx->defer_error ? (OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES), ctx->defer_error = 0) : 0;
    return NULL;
  }

  // Allocate memory for ctx->bignums if empty
  if (ctx->bignums == NULL) {
    if((ctx->bignums = sk_BIGNUM_new_null()) == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all available have been used, then create an extra BIGNUM and push to the stack. If creation fails, set error flag 
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      bn != NULL ? BN_free(bn) : 0;
      ctx->error = 1;
      return NULL;
    }
  }

 // Initialize ctx->usedth BIGNUM to zero and return it. Before returning increment the used number.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // This fills the ctx->usedth BIGNUM with zeroes
  ++(ctx->used);
  
  return ret;
}