BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If there has been an error before, return NULL.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
      return NULL;
    }
    return NULL;  
  }

  // Initialize the bignums stack, if not already.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all bignums on the stack are used, add a new one.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if (bn) {
        BN_free(bn);
      }
      ctx->error = 1;
      return NULL;
    }
  }

  // Use the next bignum on the stack and increment the pointer.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_clear(ret);
  ctx->used++;
  return ret;
}