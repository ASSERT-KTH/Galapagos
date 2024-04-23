void BN_CTX_end(BN_CTX *ctx) {
  if (ctx->error) {
    // Once an operation has failed, |ctx->stack| no longer matches the number
    // of |BN_CTX_end| calls to come. Do nothing.
    return;
  }

  ctx->used = BN_STACK_pop(&ctx->stack);
}