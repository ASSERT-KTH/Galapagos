EVP_MD_CTX *EVP_MD_CTX_new(void) {
  EVP_MD_CTX *ctx = OPENSSL_malloc(sizeof(EVP_MD_CTX));

  if (ctx) {
    EVP_MD_CTX_init(ctx);
  }

  return ctx;
}