BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // After any operation has experienced a failure, the operations that follow will fail as well.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 1;
      return NULL;
    } 
    else {
      return NULL;
    }
  }

  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 2;
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 2;
      return NULL;
    }
    if (!sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *result = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(result);
  ctx->used++;

  return result;
}