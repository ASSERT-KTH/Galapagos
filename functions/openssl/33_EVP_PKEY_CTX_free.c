void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx) {
  if (ctx == NULL) {
    return;
  }
  if (ctx->pmeth && ctx->pmeth->cleanup) {
    ctx->pmeth->cleanup(ctx);
  }
  EVP_PKEY_free(ctx->pkey);
  EVP_PKEY_free(ctx->peerkey);
  OPENSSL_free(ctx);
}