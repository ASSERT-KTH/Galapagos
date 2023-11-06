BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // When any operation fails, subsequent transactions fail too.
  if (ctx->error && ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;

      return NULL;
  }

  // Initializing the stack of BIGNUM if it's not set.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Check if the stack creation is successfully done.
    if (ctx->bignums == NULL) {
      ctx->error = 1;
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      return NULL;
    }
  }

  // Checking if all the BIG_NUM variables are used if so create new BIG_NUM and push it into the bignums stack.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();

    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      BN_free(bn);
      ctx->error = 1;
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      return NULL;
    }
  }

  // Get the value from BigNums list at the index represented by used.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);

  BN_zero(ret);
  ctx->used++;

  return ret;
}