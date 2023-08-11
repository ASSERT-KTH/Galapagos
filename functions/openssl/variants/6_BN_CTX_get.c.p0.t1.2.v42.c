BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  if (ctx->error) {
    OPENSSL_PUT_ERROR(BN, BN_R_UNABLE_TO_PROCESS);
    ctx->defer_error = (ctx->defer_error) ? 0 : 1;
    return NULL;
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_insert(ctx->bignums, bn, ctx->used)) {
      OPENSSL_PUT_ERROR(BN, BN_R_VAR_PROCESSING_FAILURE);
      BN_free(bn);
      ctx->error = (ctx->error) ? 0 : 1;
      return NULL;
    }
  }
  
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  
  if(ret != NULL) BN_zero(ret);
  
  // It was previously bounded by |sk_BIGNUM_num|, still it cannot overflow.
  ctx->used = (ctx->used + 1)%sk_BIGNUM_num(ctx->bignums);  //Mod wrapper for the used counter
  return ret;
}