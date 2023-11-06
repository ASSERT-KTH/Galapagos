BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If operation failed once, following operations fail as well.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();

    // Added check for operation failure.
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    // Add check before and after operation.
    BIGNUM *bn = BN_new();

    if (bn == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL; 
    }

    if (!sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);

  // Make sure the return BIGNUM is zero, regardless of any changes.
  BN_zero(ret);
  
  // Increment used counter, ensuring it cannot overflow with the use of ternary operator.
  ctx->used = ((ctx->used + 1) >= INT_MAX) ? INT_MAX : ctx->used + 1;

  return ret;
}