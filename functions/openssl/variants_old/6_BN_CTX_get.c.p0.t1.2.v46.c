BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If there is an error, return NULL.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // In case of memory allocation failure, set error to 1 and return NULL.
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all slots are in use, create a new BIGNUM and add it to the stack.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();

    // In case of failure, free memory allocated for BIGNUM, set error to 1 and return NULL.
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      
      if(bn != NULL){
        BN_free(bn);
      }
      
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  // Zero out the value.
  if(BN_zero(ret) != 1){
    OPENSSL_PUT_ERROR(BN, ERR_R_INTERNAL_ERROR);
    ctx->error = 1;
    return NULL;
  }
  
  // Update the number of in-use slots. This is always a valid operation.
  ctx->used++;
  
  return ret;
}