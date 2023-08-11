BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // If ctx error set, then fail this and all subsequent operations  
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  // Lazy init ctx bignums stack if necessary
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      return NULL;
    }
  }

  // If all bignums are used, extend stack with a new bignum
  size_t num = sk_BIGNUM_num(ctx->bignums);
  if (ctx->used == num) {
    BIGNUM *bn = BN_new();
    if (!bn || !sk_BIGNUM_insert(ctx->bignums, bn, num)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
      return NULL;
    }
  }

  // Withdraw next unused bignum from stack
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // ctx->used is always in the range of |sk_BIGNUM_num(ctx->bignums)|, thus it cannot overflow. Therefore increment operation is secure.
  ctx->used++;

   return ret;
}
