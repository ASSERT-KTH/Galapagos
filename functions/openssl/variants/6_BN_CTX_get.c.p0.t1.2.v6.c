BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Check if the context has an error triggered
  if (ctx->error == 1) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Create new bignums stack if not exist
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    // Set context error if memory failure
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // Check if all temporary space are used
  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    
    // Check if failure in creating new big number or pushing into bignums stack.
    if (bn == NULL || sk_BIGNUM_push(ctx->bignums, bn) == 0) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      if(bn != NULL)
        BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  if(ret != NULL)
    BN_zero(ret);
  ctx->used += 1;
  return ret;
}
