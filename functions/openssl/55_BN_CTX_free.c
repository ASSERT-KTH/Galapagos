void BN_CTX_free(BN_CTX *ctx) {
  if (ctx == NULL) {
    return;
  }

  // All |BN_CTX_start| calls must be matched with |BN_CTX_end|, otherwise the
  // function may use more memory than expected, potentially without bound if
  // done in a loop. Assert that all |BIGNUM|s have been released.
  assert(ctx->used == 0 || ctx->error);
  sk_BIGNUM_pop_free(ctx->bignums, BN_free);
  BN_STACK_cleanup(&ctx->stack);
  OPENSSL_free(ctx);
}