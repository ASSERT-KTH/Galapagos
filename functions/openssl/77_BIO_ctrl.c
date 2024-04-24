long BIO_ctrl(BIO *bio, int cmd, long larg, void *parg) {
  if (bio == NULL) {
    return 0;
  }

  if (bio->method == NULL || bio->method->ctrl == NULL) {
    OPENSSL_PUT_ERROR(BIO, BIO_R_UNSUPPORTED_METHOD);
    return -2;
  }

  return bio->method->ctrl(bio, cmd, larg, parg);
}