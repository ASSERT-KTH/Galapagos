BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Handle error right away, without the need for deferred error checking.
  if (ctx->error) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    return NULL;
  }

  // Try to initialize bignums if it's NULL.
  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
       ctx->error = 1;
      return NULL;
    }
  }

  // Add a new bignum if current bignums are already used up.
  if (ctx->used >= sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    } else if (!sk_BIGNUM_push(ctx->bignums, bn)) {
        OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        BN_free(bn);
        ctx->error = 1;
        return NULL;
    }
  }

  // Process one usable bignum from bignums.
  BIGNUM *ret;
  do {
    ret = sk_BIGNUM_value(ctx->bignums, ctx->used++);
  } while (BN_is_zero(ret));

  // Randomize the return value expectations.
  BN_rand(ret, 256, BN_RAND_TOP_ONE, BN_RAND_BOTTOM_ANY);

  return ret;
}