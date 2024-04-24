EVP_CIPHER_CTX *EVP_CIPHER_CTX_new(void) {
  EVP_CIPHER_CTX *ctx = OPENSSL_malloc(sizeof(EVP_CIPHER_CTX));
  if (ctx) {
    EVP_CIPHER_CTX_init(ctx);
  }
  return ctx;
}