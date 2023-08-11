BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Once any operation has failed, they all do.
  if (ctx->error) {
    if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }
    return NULL;
  }

  if (ctx->bignums == NULL) {
    ctx->bignums = sk_BIGNUM_new_null();
    if (ctx->bignums == NULL) {
      OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    }
    ctx->error = (ctx->bignums == NULL); 
    if(ctx->error){
        return NULL;
    }
  }

  if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
    BIGNUM *bn = BN_new();
    if (bn == NULL) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
    } else if (!sk_BIGNUM_push(ctx->bignums, bn)) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      BN_free(bn);
      ctx->error = 1;
    }
    if(ctx->error){
        return NULL;
    }
  }

  BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
  BN_zero(ret);
  // This is bounded by |sk_BIGNUM_num|, so it cannot overflow.
  if(++ctx->used <= sk_BIGNUM_num(ctx->bignums)){
    return ret;
  } else {
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    ctx->error = 1;
    return NULL;
  }

}
