BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  BIGNUM *ret = NULL;

  if (!ctx->error) {
    if (ctx->bignums == NULL) {
      ctx->bignums = sk_BIGNUM_new_null();
    }

    if (ctx->bignums != NULL) {
      if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
        BIGNUM *bn = BN_new();

        if (bn == NULL || !sk_BIGNUM_push(ctx->bignums, bn)) {
          OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
          BN_free(bn);
        } 
        else {
          ret = bn;
        }
      }
      
      if(ret == NULL) {
        ret = sk_BIGNUM_value(ctx->bignums, ctx->used)   
        if (ret) {
          BN_zero(ret);
          ctx->used++;
        }
      }
    
      if(ret == NULL && ctx->used == sk_BIGNUM_num(ctx->bignums)) {
        OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      }
    }
    else {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    }
  } 
  else {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
  }

  if(ret == NULL) {
    ctx->error = 1;
  }

  return ret;
}