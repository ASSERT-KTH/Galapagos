BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If there is an error and it is not deferred, instantly return NULL.
  if (ctx->error && !ctx->defer_error) {
    return NULL;
  }

  // Initialize bignums stack which is NULL.
  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
  }
  
  // If failed to initialize bignums, set the error and return NULL.
  if (ctx->bignums == NULL) {
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    if (ctx->defer_error) {
      ctx->error = 1;
    }
    return NULL;
  }

  // Create new BIGNUM if all in the stack are used.
  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    // If failure to create new BIGNUM, then set error and return NULL.
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      if (ctx->defer_error) {
        ctx->error = 1;
      }
      return NULL;
    }
  }

  // Get next BIGNUM without initializing it to zero.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used++);

  // Confirm that there are no critical errors happened.
  if (ctx->defer_error) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
             
    ctx->defer_error = 0;
    ret = NULL;
  }

  return ret;
}