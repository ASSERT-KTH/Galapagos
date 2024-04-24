int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int command, int arg, void *ptr) {
  int ret;
  if (!ctx->cipher) {
    OPENSSL_PUT_ERROR(CIPHER, CIPHER_R_NO_CIPHER_SET);
    return 0;
  }

  if (!ctx->cipher->ctrl) {
    OPENSSL_PUT_ERROR(CIPHER, CIPHER_R_CTRL_NOT_IMPLEMENTED);
    return 0;
  }

  ret = ctx->cipher->ctrl(ctx, command, arg, ptr);
  if (ret == -1) {
    OPENSSL_PUT_ERROR(CIPHER, CIPHER_R_CTRL_OPERATION_NOT_IMPLEMENTED);
    return 0;
  }

  return ret;
}