void BN_CTX_start(BN_CTX *ctx) {
  if (ctx->error) {
    // Once an operation has failed, |ctx->stack| no longer matches the number
    // of |BN_CTX_end| calls to come. Do nothing.
    return;
  }

  if (!BN_STACK_push(&ctx->stack, ctx->used)) {
    ctx->error = 1;
    // |BN_CTX_start| cannot fail, so defer the error to |BN_CTX_get|.
    ctx->defer_error = 1;
  }
}