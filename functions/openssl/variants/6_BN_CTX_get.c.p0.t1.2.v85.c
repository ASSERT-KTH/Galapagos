BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  BIGNUM *ret;

  // Once any operation has failed, they all do.
  if (ctx->error && !ctx->defer_error) {
    goto err;
  } else if (ctx->error && ctx->defer_error) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    ctx->defer_error = 0;
    goto err;
  }

  if (!ctx->bignums) {
    if ((ctx->bignums = sk_BIGNUM_new_null()) == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
      goto err;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    ret = BN_new();

    if (!ret || !sk_BIGNUM_push(ctx->bignums, ret)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(ret);
      ctx->error = 1;
      goto err;
    }
  }

  ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  ctx->used++;
  
  return ret;

err:
  return NULL;
}