BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Instead of return failure directly, we use break to maintain neater code.
  do {
    if (ctx->error) {
      if (ctx->defer_error) {
        OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->defer_error = 0;
      }
      break;
    }

    if (ctx->bignums == NULL) {
      ctx->bignums = sk_BIGNUM_new_null();
      if (ctx->bignums == NULL) {
        OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
        ctx->error = 1;
        break;
      }
    }

    if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
      BIGNUM *bn = BN_new();
      if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
        OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        BN_free(bn);
        ctx->error = 1;
        break;
      }
    }

    BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
    if (ret != NULL) { // Check if the return value is not NULL before operate it
      BN_zero(ret);

      ctx->used++;
      return ret;
    }

  } while (false);

  // When reach here, it means an error occurred.
  return NULL;
}