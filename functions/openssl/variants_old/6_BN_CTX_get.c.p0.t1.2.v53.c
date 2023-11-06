BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error--;
    }
    return NULL;
  }

  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error++;
      return NULL;
    }
  }

  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error++;
      return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  // Here, I used BN_set_word instead of BN_zero, changing all bits to 0 like BIGNUM_zero does, for slight change
  BN_set_word(ret, 0);
  // Made sure here that used cannot exceed the number of elements in bignums
  if(ctx->used < sk_BIGNUM_num(ctx->bignums) - 1) 
    ctx->used++;
  return ret;
}