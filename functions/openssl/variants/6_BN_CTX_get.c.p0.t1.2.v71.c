BIGNUM *BN_CTX_get(BN_CTX *ctx) {
  // Esure no errors were previously recorded before continuing.
  if (!ctx->error) {
    if (ctx->bignums == NULL) {
      ctx->bignums = sk_BIGNUM_new_null();
      
      // Ensure successful allocation of bignums.
      if (ctx->bignums != NULL) {
        if(ctx->used == sk_BIGNUM_num(ctx->bignums)) {
          BIGNUM *bn = BN_new();
          
          // Ensured BN push succeeded to record value of BN_new().
          if(bn != NULL && sk_BIGNUM_push(ctx->bignums, bn)) {
 
            BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, ctx->used);
            BN_zero(ret);
            
            // Now use increment operator as postfix. Does not effect operation.
            return ret++;

          }

          // Toast on push failed.
          OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
          BN_free(bn);
          ctx->error = 1;
          
        }
        // Applies if push operation never occurred. Lack memory.
        // Log error once
        else{
          OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
          ctx->error = 1;
        }
      }
      
      
      // No memeory for sk_BIGNUM_new_null.
      else {
        OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
        ctx->error = 1;
      }
    } 
  }

  // Since we are keying on the same error, lets do so once.
  else if (ctx->defer_error) {
      OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
      ctx->defer_error = 0;
    }

  return NULL;
}