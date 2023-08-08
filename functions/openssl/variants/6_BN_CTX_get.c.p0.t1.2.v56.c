BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }
  
  // Checks if bignums pointer is NULL, if so, it initializes it. 
  // Otherwise, it goes to the next operation.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
  }

  // If something went wrong with memory allocation, indicate error and exit 
  if (ctx->bignums == NULL) {
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    ctx->error = 1;
    return NULL;
  }

  // Create new BIGNUM and push into stack if out of pre-created ones.
  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    // In the original version if something went wrong at this point, the new object was immediately freed. 
    // Now, let's try to push it again.
    if (bn == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    } else if (!sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if (!sk_BIGNUM_push(ctx->bignums, bn)) {
        BN_free(bn);
        ctx->error = 1;
        return NULL;
      }
    }
  }

  // Picking bignum from stack and zeroing this value.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used++);
  if(BN_is_zero(ret) != 1) {
    BN_zero(ret);
  }

  return ret;
}