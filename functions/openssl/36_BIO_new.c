BIO *BIO_new(const BIO_METHOD *method) {
  BIO *ret = OPENSSL_malloc(sizeof(BIO));
  if (ret == NULL) {
    OPENSSL_PUT_ERROR(BIO, ERR_R_MALLOC_FAILURE);
    return NULL;
  }

  OPENSSL_memset(ret, 0, sizeof(BIO));
  ret->method = method;
  ret->shutdown = 1;
  ret->references = 1;

  if (method->create != NULL && !method->create(ret)) {
    OPENSSL_free(ret);
    return NULL;
  }

  return ret;
}