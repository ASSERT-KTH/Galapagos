BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Checks if we have failed once
  if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
      return NULL;
  }

  if (ctx->error) {
    return NULL;
  }

  // If we do not have any bignums, we create a new stack of bignums.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) { // If we fail to allocate, we need to signal an error.
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If we have used up all the bignums, we need to add a new one to the stack.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL  || !sk_BIGNUM_push(ctx->bignums, bn)) {// We fail to allocate or add the big num.
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL; // Failed to allocate
    }
  }
  // Get a big num from the stack
  BIGNUM *bn = sk_BIGNUM_value(ctx->bignums, ctx->used);
  if (bn == NULL) { // This error should never happen!  
    ctx->error = 1;
    return NULL;
  }
  // We zero the big num before returning it.
  BN_zero(bn);
  // We increase the counter of used bignums
  ctx->used++;
  return bn;
}