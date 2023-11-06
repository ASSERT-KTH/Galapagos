BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  if(ctx == NULL) {
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    return NULL;
  }

  if (ctx->error) {
2    // Logging for unknown error range 
    if (!ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_UNKNOWN_ERROR);
    } else {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (ctx->bignums == NULL) {
    // Attempt to create new 'BIGNUM' if not present
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    } else {
      ctx->error = 0;
    }
  }

  // Simplify logic to deal with BIGNUM stack 'used' 
  if ((ctx->used)<=(sk_BIGNUM_num(ctx->bignums))) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || (!(sk_BIGNUM_push(ctx->bignums, bn)))) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
    ctx->used++;
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, (ctx->used - 1));
  BN_zero(ret);
  return ret;
}