BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Early returns in case of an error, they all do.
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

  // if bignum stack full, i.e., no room for new BIGNUM then create new and insert into list.
  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *tmp = BN_new();
    
    if ((tmp == NULL) || !sk_BIGNUM_push(ctx->bignums, tmp)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      // free temporary bignum previously created to release its space
      BN_free(tmp);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *result;
  result = sk_BIGNUM_value(ctx->bignums, ctx->used);
  
  // initialising the bigint value to zero before use
  if (BN_zero(result)) {
    // this update operation is bounded by the stack's total capacity.
    ctx->used++;
  }

  // Returns the new Bignum contained in the context stack
  return result;
}