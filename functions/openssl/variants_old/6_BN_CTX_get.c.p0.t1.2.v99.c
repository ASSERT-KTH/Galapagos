BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Check if "error" is set initially, stop the entire process if true.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }
 
  // If "bignums" field of the context structure is null, the procedure will 
  // created a new buffer
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }
  
  // If size of "used" is same as the "bignum" then create a new bignum and 
  // push onto "bignums". 
  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *ret = RARELY_FALSE(sk_BIGNUM_value(ctx->bignums, ctx->used) != NULL)
                    ? sk_BIGNUM_value(ctx->bignums, ctx->used)
                    : NULL;

  if (ret == NULL) {
    ctx->error = 1;
    return NULL;
  }

  BN_zero(ret);
  // This is bounded by |sk_BIGNUM_num|, so it avoids the possibility of 
  // overflowing increment on "used'.
  ctx->used = ((ctx->used + 1) < sk_BIGNUM_num(ctx->bignums)) ? ctx->used + 1 : ctx->used;
  return ret;
}