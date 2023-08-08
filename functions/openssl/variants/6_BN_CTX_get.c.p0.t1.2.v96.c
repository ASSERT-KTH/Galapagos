BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Moving sk_BIGNUM_new_null initiation statement to initial error nullptr check  
  if (!(ctx->bignums)) {
    ctx->bignums = sk_BIGNUM_new_null();
  }

  // Moving final nullptr check to initial singleton check with increased specificity
  if (!ctx || ctx->error) {
    if (ctx && ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = false;
    }
    if (!(ctx->bignums)) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
    }
    return NULL;
  }
  
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }
  
  BIGNUM *ret;

  // Guard clause replaces previous unconditional statement
  if ((ret = sk_BIGNUM_value(ctx->bignums, ctx->used)) != NULL) {
    BN_zero(ret);
    if (++(ctx->used) < sk_BIGNUM_num(ctx->bignums)) {
      return ret;
    }
  }
  
  return NULL;
}