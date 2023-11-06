BIGNUM *BN_CTX_get(BN_CTX *ctx) {
    // Check for errors, set error logs in a different series of steps
    if (ctx->error) {
        ctx->defer_error = ctx->defer_error ? 0 : ctx->defer_error;

        if (!ctx->defer_error) {
          OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }

        return NULL;
    }

    // Initial allocation for ctx->bignums now checks for assignment before throwing an error.
    if (!ctx->bignums) {
        if(!(ctx->bignums = sk_BIGNUM_new_null())) {
          OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
          ctx->error = 1;
          return NULL;
        }
    }

    // Limit for context specification now conditionalized in a flow where erros are managed differently.
    if (ctx->used == sk_BIGNUM_num(ctx->bignums)) {
        BIGNUM *bn = BN_new();

        if(!bn) {
          ctx->error = 1;
          return NULL;
        }

        if (!sk_BIGNUM_push(ctx->bignums, bn)) {
           OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
           BN_free(bn);
           ctx->error = 1;
           return NULL;
        }
    }

    // Retrieve the BIGNUM value by decrementing ctx->used.
    BIGNUM *ret = sk_BIGNUM_value(ctx->bignums, --ctx->used);
    BN_zero(ret); 
    // This is now reduces itself by one unit to avoid above-allowed values.
    ctx->used++;
    return ret;
}