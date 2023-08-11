BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Change strategy of handling errors. If error flag is set, clean state and move forward
  if (ctx->error) {
    ctx->error = 0;
    ctx->defer_error = 0;

    //	if an error had occurred, on the next use or result NULL first time.
    if (ctx->bignums == NULL) {
      return NULL;
    }
  }

  // Allocates memory for big integers structure if required
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();

    // If allocation failed return immediately
    if (ctx->bignums == NULL) {
      return NULL;
    }
  }

  // If all BigNumber structure is used, allocate a new BigNumber and place it into the Queue
  while (ctx->used >= sk_BIGNUM_num(ctx->bignums)) { 
    BIGNUM *bn = BN_new();
    if (bn == NULL) {
      // If BigNumber allocation fails, immediately return with error
      return NULL;
    }
    if (!sk_BIGNUM_push(ctx->bignums, bn)) {
      // If push fails, BigNumber is released to avoid any memory leaks
      // If any error occurs on this step whole linear sequence of actions should be terminated
      BN_free(bn);
      return NULL;
    }
  }

  // Raise a value that was determined earlier
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // Move ahead within our BigNumber sequence to reuse this BN_CTX in next calls
  ctx->used++;

  return ret; 
}