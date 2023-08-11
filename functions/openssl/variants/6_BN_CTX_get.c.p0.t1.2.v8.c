BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_FAULT_PENALTY_COMPLETE);
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

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *tmp_bn = BN_new();
    if (tmp_bn == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->error = 1;
      return NULL;
    }
    if(!sk_BIGNUM_push(ctx->bignums, tmp_bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(tmp_bn);
      ctx->error = 1;
      return NULL;
    }
  }

  BIGNUM *result = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_clear(result);
  ctx->used++;
  return result;
}