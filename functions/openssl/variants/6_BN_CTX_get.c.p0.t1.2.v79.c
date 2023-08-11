BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, postpone error generation.
  if (ctx->error) {
    if (ctx->defer_error) {
      ctx->defer_error = 0;
    } else {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    return NULL;
  }

  // If there's no big number set, try to initialize it.
  if (!ctx->bignums) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (!ctx->bignums) {
      ctx->error = 1;
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      return NULL;
    }
  }

  // Expand the capacity of bignums if all are used.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (!bn || !sk_BIGNUM_push(ctx->bignums, bn)) {
      ctx->error = 1;
      if(bn) BN_free(bn);          // Only free bn if it was successfully created.
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      return NULL;
    }
  }

  // Get and initialize an available big number.
  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  if(ret) {
    BN_zero(ret);
    // As increment by 1 will not cause overflow given |sk_BIGNUM_num| bound
    // Use post-increment for consumption clarity	
    ctx->used++;
  }

  return ret;
}