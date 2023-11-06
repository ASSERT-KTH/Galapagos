BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Perform check for NULL context
  if (!ctx) {
    OPENSSL_PUT_ERROR(BN, BN_R_NULL_CONTEXT);
    return NULL;
  }

  // If the operation has previously failed, subsequent operations fail as well
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (!bn || sk_BIGNUM_push(ctx->bignums, bn) == 0) {
      if (bn) {
        OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        BN_free(bn);
      }
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_clear(ret);
  ctx->used++;
  
  return ret;
}