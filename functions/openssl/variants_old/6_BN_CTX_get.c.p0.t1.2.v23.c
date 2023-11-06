BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Checking the inverse condition cleans the code.
  if (!ctx->error) {
    if (ctx->bignums == NULL) {
      ctx->bignums = sk_BIGNUM_new_null();
      // Use "not equal to NULL" for comparison.
      if (ctx->bignums != NULL) {
        
        if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
          BIGNUM *bn = BN_new();

          if (bn != NULL) {
            if(!sk_BIGNUM_push(ctx->bignums, bn)) {
                OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
                BN_free(bn);
                ctx->error = 1;
            }
          }

        }

        BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
        if (ret != NULL) {
          BN_zero(ret);
          ctx->used++;
          return ret;
        }
      } 
    }

    else {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
      ctx->error = 1;
    }

  } else if (ctx->defer_error) {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    ctx->defer_error = 0;
  }
  
  return NULL;
}